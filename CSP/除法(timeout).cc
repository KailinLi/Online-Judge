#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 5;
int a[MAXN];
int n, m;
int BIT[MAXN << 1];
inline int lowbit(int x) {
    return x & (-x);
}
inline int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= lowbit(x);
    }
    return res;
}
inline void edit(int x, int delta) {
    while (x < (MAXN << 1)) {
        BIT[x] += delta;
        x += lowbit(x);
    }
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	REP(i, n) {
		scanf("%d", a + i + 1);
		edit(i + 1, a[i + 1]);
	}
	int type;
	int l, r, v;
	while (m--) {
		scanf("%d", &type);
		if (type == 2) {
			scanf("%d %d", &l, &r);
			printf("%d\n", sum(r) - sum(l - 1));
		}
		else {
			scanf("%d %d %d", &l, &r, &v);
			for (int i = l; i <= r; ++i) {
				if (!(a[i] % v)) {
					int tmp = a[i];
					a[i] /= v;
					tmp -= a[i];
					edit(i, -tmp);
				}
			}
		}
	}
	return 0;
}