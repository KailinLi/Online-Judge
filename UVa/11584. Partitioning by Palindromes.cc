#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 1000 + 5;
char input[MAXN];
int pre[MAXN][MAXN];
int dp[MAXN];
int n;
int preHandle(int i, int j) {
	if (i == j) return pre[i][j] = 1;
	else if (i + 1 == j)
		return pre[i][j] = (input[i] == input[j] ? 1 : 0);
	if (pre[i][j] != -1) return pre[i][j];
	if (input[i] == input[j]) {
		return pre[i][j] = preHandle(i + 1, j - 1);
	}
	else {
		return pre[i][j] = 0;
	}
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	getchar();
	while (n--) {
		scanf("%s", input);
		memset(pre, -1, sizeof(pre));
		REP(i, strlen(input) + 1) dp[i] = 0x3f3f3f3f;
		dp[0] = 0;
		for (int i = 0; i < strlen(input); ++i) {
			REP(j, i + 1) {
				if (preHandle(j, i) == 1) {
					if (!j) dp[i + 1] = 1;
					else if (dp[j] + 1 < dp[i + 1])
						dp[i + 1] = dp[j] + 1;
				}
			}
		}
		printf("%d\n", dp[strlen(input)]);
	}
}