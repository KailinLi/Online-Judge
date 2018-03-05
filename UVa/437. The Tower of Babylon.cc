#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 30 + 5;
int dp[MAXN][3];
int block[MAXN][3];
int n;

int DAG(int i, int j) {
	if (dp[i][j] > 0) return dp[i][j];
	int& res = dp[i][j];
	int tmpi = 0;
	int currentXY[2];
	int current[2];
	for (int t = 0; t < 3; ++t)
		if (t != j)
			currentXY[tmpi++] = block[i][t];
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < 3; ++b) {
			tmpi = 0;
			for (int t = 0; t < 3; ++t)
				if (t != b)
					current[tmpi++] = block[a][t];
			if (current[0] < currentXY[0] && current[1] < currentXY[1])
				res = max(res, DAG(a, b));
		}
	}
	return res += block[i][j];
}


int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d", block[i], block[i] + 1, block[i] + 2);
			sort(block[i], block[i] + 3);
		}
		memset(dp, 0, sizeof(dp));
		int res = 0;
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < 3; ++b) {
				res = max(res, DAG(a, b));
			}
		}
		printf("Case %d: maximum height = %d\n", ++kase, res);
	}
}