#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (90 + 5)
int dp[MAXN];
int n;

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 90; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", dp[n]);
    }
    return 0;
}