#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 1000 + 5;
int frq[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN][MAXN];
int n;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	REP(i, n) scanf("%d", frq + i);
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			if (i == j) sum[i][j] = frq[i];
			else sum[i][j] = sum[i][j - 1] + frq[j];
	for (int len = 1; len <= n; ++len) {
		for (int i = 0; i + len <= n; ++i) {
			int j = i + len - 1;
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			int tmp_min = 0x3f3f3f3f;
			for (int k = i; k < j; ++k) {
				tmp_min = min(tmp_min, dp[i][k] + dp[k + 1][j] + sum[i][k] + sum[k + 1][j]);
			}
			dp[i][j] = tmp_min;
		}
	}
	printf("%d\n", dp[0][n - 1]);
	return 0;
}