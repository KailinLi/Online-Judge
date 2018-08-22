#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
struct Record {
    char mark[50][MAXN];
    int type[50];
    char name[MAXN];
    int is_path;
};
Record record[MAXN];
int n, m;
char input[MAXN];
char save[MAXN];
char res[MAXN << 1];
int pos;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    getchar();
    REP(i, n) {
        scanf("%s %s", input, record[i].name);
        int flg = input[strlen(input) - 1] == '/';
        int cnt = 0;
        char *p = strtok(input, "/");
        while (p) {
            if (*p == '<') {
                if (!strcmp(p, "<int>")) record[i].type[cnt++] = 2;
                else if (!strcmp(p, "<str>")) record[i].type[cnt++] = 3;
                else if (!strcmp(p, "<path>")) record[i].type[cnt++] = 4;
            }
            else {
                strcpy(record[i].mark[cnt], p);
                record[i].type[cnt++] = 1;
            }
            p = strtok(NULL, "/");
        }
        record[i].is_path = flg;
    }

    while (m--) {
        int success = 0;
        scanf("%s", save);
        REP(i, n) {
            pos = 0;
            strcpy(input, save);
            int flg = input[strlen(input) - 1] == '/';
            int cnt = 0;
            char *p = strtok(input, "/");
            int match = 1;
            while (p && match) {
                if (record[i].type[cnt] == 1) {
                    if (strcmp(p, record[i].mark[cnt])) {
                        match = 0;
                        break;
                    }
                }
                else if (record[i].type[cnt] == 2) {
                    for (int c = 0; p[c]; ++c) if (!isdigit(p[c])) {
                        match = 0;
                        break;
                    }
                    if (pos) res[pos++] = ' ';
                    int c = 0;
                    while (p[c] == '0') ++c;
                    strcpy(res + pos, p + c);
                    pos = (int)strlen(res);
                }
                else if (record[i].type[cnt] == 3) {
                    for (int c = 0; p[c]; ++c) if (!isalnum(p[c]) && p[c] != '-'
                                                    && p[c] != '_' && p[c] != '.') {
                        match = 0;
                        break;
                    }
                    if (pos) res[pos++] = ' ';
                    strcpy(res + pos, p);
                    pos = (int)strlen(res);
                }
                else if (record[i].type[cnt] == 4) {
                    if (pos) res[pos++] = ' ';
                    strcpy(res + pos, p);
                    pos = (int)strlen(res);
                    p = strtok(NULL, "/");
                    while (p) {
                        res[pos++] = '/';
                        strcpy(res + pos, p);
                        pos = (int)strlen(res);
                        p = strtok(NULL, "/");
                    }
                    if (flg) res[pos++] = '/';
                    flg = 0;
                }
                else {
                    match = 0;
                    break;
                }
                ++cnt;
                p = p ? strtok(NULL, "/") : p;
            }
            if (!(!match || p || record[i].type[cnt] || record[i].is_path != flg)) {
                success = 1;
                res[pos] = '\0';
                printf("%s %s\n", record[i].name, res);
                break;
            }
        }
        if (!success) printf("404\n");
    }
    return 0;
}