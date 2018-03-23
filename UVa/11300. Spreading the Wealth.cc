#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000000 + 5;
long long input[MAXN];
long long c[MAXN];
int n;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d", &n) == 1) {
		long long sum = 0;
		REP(i, n) {
			scanf("%lld", input + i);
			sum += *(input + i);
		}
		long long m = sum / n;
		c[0] = 0;
		for (int i = 1; i < n; ++i)
			c[i] = c[i - 1] + input[i] - m;
		sort(c, c + n);
		long long mid = c[n >> 1];
		sum = 0;
		REP(i, n) {
			sum += abs(*(c + i) - mid);
		}
		printf("%lld\n", sum);
	}
	return 0;
}