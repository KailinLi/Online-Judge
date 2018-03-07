#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 50 + 5;
int l[MAXN];
const int MAXM = 180 * 50 + 678 + 5;
int dp[MAXM];
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
		int time = 0;
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = s - 1; j >= l[i - 1]; --j) {
				if (dp[j - l[i - 1]] != -1)
					dp[j] = max(dp[j], dp[j - l[i - 1]] + 1);
			}
		}
		int ans = -1;
		for (int i = s - 1; i > 0; --i) {
			if (dp[i] != -1 && (ans == -1 || dp[ans] < dp[i]))
				ans = i;
		}
		if (ans != -1)
			printf("Case %d: %d %d\n", ++kase, dp[ans] + 1, ans + 678);
		else
			printf("Case %d: %d %d\n", ++kase, 1, 678);
	}
}