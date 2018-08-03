#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 80 + 5;
const int MAXM = 100 + 5;
char buf[MAXM][MAXN];
char str[MAXM][MAXN + MAXM];
int len[MAXM];
int m, n;

int find_p(char *s, int i) {
    int len = 0;
    if (s[++i] != '{') return -1;
    if (s[++i] != ' ') return -1;
    ++i;
    while (s[i++] != ' ')
        ++len;
    return len;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &m, &n);
    getchar();
    REP(i, m)
        fgets(buf[i], MAXN, stdin);
    REP(i, n) {
        fgets(str[i], MAXN + MAXM, stdin);
        REP(j, MAXN) {
            if (str[i][j] == ' ') {
                len[i] = j;
                break;
            }
        }
    }
    REP(i, m) {
        REP(j, MAXM) {
            if (buf[i][j] == '{') {
                int l = find_p(buf[i], j);
                if (l == -1) {
                    printf("{");
                    continue;
                }
                REP(k, n) {
                    if (len[k] == l && !strncmp(str[k], buf[i] + j + 3, l)) {
                        int pos = l + 2;
                        while (str[k][pos] != '\"')
                            printf("%c", str[k][pos++]);
                    }
                }
                j += 5 + l;
            }
            else if (buf[i][j] != '\n') printf("%c", buf[i][j]);
            else {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}