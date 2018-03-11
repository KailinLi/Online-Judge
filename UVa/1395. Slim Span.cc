#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 100 + 5;
const int MAXM = (MAXN * (MAXN - 1)) >> 1;
struct Edge {
	int u;
	int v;
	int w;
	bool operator< (const Edge& rhs) const {
		return w < rhs.w;
	}
};
Edge edge[MAXM];
int pa[MAXN];
int n, eCnt;
int findP(int x) {
	return (pa[x] == x) ? x : (pa[x] = findP(pa[x]));
}
void unionP(int rx, int ry) {
	pa[rx] = ry;
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &eCnt) && n) {
		int res = 0x3f3f3f3f;
		REP(i, eCnt)
			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		sort(edge, edge + eCnt);
		REP(l, eCnt - n + 2) {
			REP(i, n)
				pa[i + 1] = i + 1;
			int tmpCnt = 0;
			for (int r = l; r < eCnt; ++r) {
				int rx = findP(edge[r].u);
				int ry = findP(edge[r].v);
				if (rx != ry) {
					unionP(rx, ry);
					if (++tmpCnt == n - 1) {
						res = min(res, edge[r].w - edge[l].w);
						break;
					}
				}
			}
		}
		printf("%d\n", res == 0x3f3f3f3f ? -1 : res);
	}
}