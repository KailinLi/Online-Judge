#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1000000 + 5;
int ground[MAXN];
int ceil[MAXN];
int level[MAXN];
int t, n;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", ::ground + i);
		for (int i = 0; i < n; ++i) scanf("%d", ::ceil + i);
		int h = ceil[0];
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (h > ceil[i]) h = ceil[i];
			else if (h < ground[i]) h = ground[i];
			level[i] = h;
		}
		h = ceil[n - 1];
		for (int i = n - 1; i >= 0; --i) {
			if (h > ceil[i]) h = ceil[i];
			else if (h < ground[i]) h = ground[i];
			res += min(level[i], h) - ground[i];
		}
		printf("%d\n", res);
	}
}