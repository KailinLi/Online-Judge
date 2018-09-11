#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
int dp[MAXN][MAXN];
int u, v;
int n, kase;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    REP(i, MAXN) REP(j, MAXN) dp[i][j] = INF;
    while (scanf("%d %d", &u, &v) == 2) {
        if (!u && !v) {
            double sum = 0.0, cnt = 0;
            ++n;
            REP(k, n) REP(i, n) REP(j, n)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            REP(i, n) REP(j, n) {
                if (i != j && dp[i][j] != INF) {
                    sum += dp[i][j];
                    ++cnt;
                }
            }
            if (n != 1) printf("Case %d: average length between pages = %.3f clicks\n", ++kase, sum / cnt);
            REP(i, MAXN) REP(j, MAXN) dp[i][j] = (i == j) ? 0 : INF;
            n = 0;
        }
        else {
            n = max(n, max(v, u));
            dp[u][v] = 1;
        }
    }
    return 0;
}