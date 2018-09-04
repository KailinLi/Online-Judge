#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
int dp[MAXN];
int p[500 + 5];
int w[500 + 5];
int t, w1, w2, n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &w1, &w2, &n);
        REP(i, n) scanf("%d %d", p + i + 1, w + i + 1);
        REP(i, w2 - w1) dp[i + 1] = INF;
        REP(i, n) for (int j = w[i + 1]; j <= w2 - w1; ++j) {
            if (dp[j - w[i + 1]] != INF) {
                dp[j] = min(dp[j], dp[j - w[i + 1]] + p[i + 1]);
            }
        }
        if (dp[w2 - w1] == INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[w2 - w1]);
    }
    return 0;
}