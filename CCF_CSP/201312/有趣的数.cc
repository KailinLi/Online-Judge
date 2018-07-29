#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
const int MOD = 1000000007;
int dp[MAXN][6];
int n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2 % MOD) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2 % MOD) % MOD;
        dp[i][4] = (dp[i - 1][2] + (dp[i - 1][1] + dp[i - 1][4] * 2 % MOD) % MOD) % MOD;
        dp[i][5] = (dp[i - 1][3] + (dp[i - 1][4] + dp[i - 1][5] * 2 % MOD) % MOD) % MOD;
    }
    printf("%d\n", dp[n][5]);
    return 0;
}