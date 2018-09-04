#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2000 + 5;
int w[MAXN];
int n, k;
int dp[MAXN >> 1][MAXN];

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &k) != EOF) {
        REP(i, n) scanf("%d", w + i + 1);
        memset(dp, 0, sizeof(dp));
        sort(w + 1, w + 1 + n);
        for (int i = 1; i <= k; ++i)
            for (int j = i * 2; j <= n; ++j) {
                if (j == i * 2) dp[i][j] = INF;
                else dp[i][j] = dp[i][j - 1];
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] + (int)pow(w[j] - w[j - 1], 2));
            }
        printf("%d\n", dp[k][n]);
    }
    return 0;
}