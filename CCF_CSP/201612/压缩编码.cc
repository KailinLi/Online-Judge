#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 1000 + 5;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXN];
int sum[MAXN];
int n;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
    REP(i, n) {
        scanf("%d", sum + i);
        if (i) sum[i] += sum[i - 1];
    }
	for (int len = 1; len <= n; ++len) {
		for (int i = 0; i + len <= n; ++i) {
			int j = i + len - 1;
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			int tmp_min = INF;
			for (int k = i; k < j; ++k) {
				tmp_min = min(tmp_min, dp[i][k] + dp[k + 1][j] + sum[j] - (i ? sum[i - 1] : 0));
			}
			dp[i][j] = tmp_min;
		}
	}
	printf("%d\n", dp[0][n - 1]);
	return 0;
}