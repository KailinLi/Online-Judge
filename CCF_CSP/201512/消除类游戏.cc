#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 30 + 5;
int num[MAXN][MAXN];
int res[MAXN][MAXN];
int m, n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &m, &n);
    REP(i, m) REP(j, n) scanf("%d", *(num + i) + j);
    memset(res, -1, sizeof(res));
    REP(i, m) {
        int begin = 0, len = 0;
        for (int j = 1; j <= n; ++j) {
            if (num[i][j - 1] == num[i][j]) {
                ++len;
                continue;
            }
            else if (len >= 2)
                REP(k, len + 1) res[i][begin + k] = 0; 
            begin = j;
            len = 0;
        }
    }
    REP(i, n) {
        int begin = 0, len = 0;
        for (int j = 1; j <= m; ++j) {
            if (num[j - 1][i] == num[j][i]) {
                ++len;
                continue;
            }
            else if (len >= 2)
                REP(k, len + 1) res[begin + k][i] = 0;
            begin = j;
            len = 0;
        }
    }
    REP(i, m) {
        int flg = 0;
        REP(j, n) {
            if (flg) printf(" ");
            if (res[i][j] == -1) printf("%d", num[i][j]);
            else printf("0");
            flg = 1;
        }
        printf("\n");
    }
    return 0;
}