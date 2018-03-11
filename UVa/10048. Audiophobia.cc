#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 100 + 5;
const int INF = 1000000000;
int dp[MAXN][MAXN];
int c, s, q;

int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int kase = 0;
	while (scanf("%d %d %d", &c, &s, &q) == 3 && c) {
		int u, v, w;
		REP(i, c) {
			dp[i][i] = 0;
			for (int j = i + 1; j < c; ++j)
				dp[i][j] = dp[j][i] = INF;
		}
		while (s--) {
			scanf("%d %d %d", &u, &v, &w);
			--u, --v;
			dp[v][u] = dp[u][v] = min(dp[u][v], w);
		}
		REP(k, c)
			REP(i, c)
				REP(j, c)
					if (dp[i][k] < INF && dp[k][j] < INF)
						dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
		if (kase) printf("\n");
		printf("Case #%d\n", ++kase);
		while (q--) {
			scanf("%d %d", &u, &v);
			--u, --v;
			if (dp[u][v] == INF)
				printf("no path\n");
			else
				printf("%d\n", dp[u][v]);
		}
	}
	return 0;
}