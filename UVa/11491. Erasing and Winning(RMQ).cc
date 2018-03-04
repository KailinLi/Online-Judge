#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100000 + 5;
char input[MAXN];
int isExist[MAXN];
int n, d;
int dp[MAXN][17];
void ST(int n) {
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i - 1;
    }
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            dp[j][i] = (input[dp[j][i - 1]] >= input[dp[j + (1 << (i - 1))][i - 1]])
						? dp[j][i - 1] : dp[j + (1 << (i - 1))][i - 1];
        }
    }
}
int RMQ(int left, int right) {
	++left;
	++right;
    int k = 0;
    while ((1 << (k + 1)) <= right - left + 1)
        ++k;
    return (input[dp[left][k]] >= input[dp[right - (1 << k) + 1][k]])
			? dp[left][k] : dp[right - (1 << k) + 1][k];
}

int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &d) == 2 && n) {
		memset(isExist, 0, sizeof(isExist));
		scanf("%s", input);
		ST(n);
		int pos = 0;
		while (d > 0 && pos + d < n) {
			int k = RMQ(pos, pos + d);
			for (int i = pos; i < k; ++i) {
				isExist[i] = 1;
				--d;
			}
			pos = k + 1;
		}
		while (d > 0 && pos < n) {
			isExist[pos] = 1;
			--d;
			++pos;
		}
		for (int i = 0; i < n; ++i)
			if (!isExist[i])
				printf("%c", input[i]);
		printf("\n");
	}
}