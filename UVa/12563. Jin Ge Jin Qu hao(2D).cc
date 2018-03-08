#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 50 + 5;
int l[MAXN];
const int MAXM = 180 * 50 + 678 + 5;
int dp[MAXN][MAXM];
int t, n, s;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	int kase = 0;
	while (t--) {
		scanf("%d %d", &n, &s);
		REP(i, n) scanf("%d", l + i);
		memset(dp, -1, sizeof(dp));
		REP(i, n + 1) dp[i][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < s; ++j) {
				if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j];
				if (j - l[i - 1] >= 0 && dp[i - 1][j - l[i - 1]] != -1)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - l[i - 1]] + 1);
			}
		}
		int res = -1, t_i = 0;
		for (int j = s - 1; j >= 0; --j) {
			for (int i = 1; i <= n; ++i) {
				if (dp[i][j] != -1 && (res == -1 || dp[t_i][res] < dp[i][j])) {
					res = j;
					t_i = i;
				}
			}
		}
		printf("Case %d: %d %d\n", ++kase, dp[t_i][res] + 1, res + 678);
	}
}