#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const char INF = 127;
const int MAXN = 80 + 10;
char input[MAXN];
char query[100 * 12][MAXN];
char res[100 * 12][MAXN];
char buf[MAXN];
int q_pos = 1;
int n, m;
int next_p(char a, char b, char c, int i) {
    while (input[i] != a && input[i] != b) {
        if (input[i] == '\n' || input[i] == '\0') {
            if (!fgets(input, MAXN, stdin)) break;
            i = 0;
        }
        while (input[i] == ' ' || input[i] == c) ++i;
    }
    return i;
}
int word(int i) {
    ++i;
    int j = 0;
    while (input[i] != '\"') {
        if (input[i] == '\\') {
            ++i;
        }
        buf[j++] = input[i++];
    }
    buf[j] = '\0';
    return i + 1;
}
int object(int i) {
    ++i;
    int pos = q_pos - 1;
    while (true) {
        i = next_p('}', '\"', ' ', i);
        if (input[i] == '}') break;
        i = word(i);
        strcpy(query[q_pos], query[pos]);
        query[q_pos][strlen(query[q_pos])] = '.';
        strcpy(query[q_pos] + strlen(query[q_pos]), buf);    // key
        i = next_p('{', '\"', ':', i);
        if (input[i] == '{') {
            res[q_pos++][0] = INF;
            i = object(i);
        }
        else {
            i = word(i);
            strcpy(res[q_pos++], buf);
        }
        i = next_p('}', ',', ' ', i);
        if (input[i] == ',') ++i;
    }
    return i + 1;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    getchar();
    fgets(input, MAXN, stdin);
    *res[0] = INF;
    object(0);
    while (m--) {
        scanf("%s", input);
        int flg = 0;
        REP(i, q_pos) {
            if (!strcmp(query[i] + 1, input)) {
                flg = 1;
                if (*res[i] == INF) printf("OBJECT\n");
                else printf("STRING %s\n", res[i]);
            }
        }
        if (!flg) printf("NOTEXIST\n");
    }
    return 0;
}