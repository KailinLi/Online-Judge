#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int num[MAXN][MAXN];
int m, n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &m, &n);
    REP(i, m) REP(j, n) scanf("%d", *(num + i) + j);
    for (int i = n - 1; i >= 0; --i) {
        int flg = 0;
        for (int j = 0; j < m; ++j) {
            if (flg) printf(" ");
            printf("%d", num[j][i]);
            flg = 1;
        }
        printf("\n");
    }
    return 0;
}