#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 100000 + 5;
const int MAXM = 400000 + 5;
struct Edge {
	int to;
	int w;
	int next;
};
int weight[MAXM];
int wCnt;
Edge edge[MAXM];
int head[MAXN];
int eCnt;
void addEdge(int u, int v, int w) {
	edge[++eCnt].to = v;
	edge[eCnt].w = w;
	edge[eCnt].next = head[u];
	head[u] = eCnt;
}
int n, m;
int vis[MAXN];
bool dfs(int u, int w) {
	if (u == n) return true;
	vis[u] = 1;
	for (int e = head[u]; e != 0; e = edge[e].next) {
		if (edge[e].w <= w && !vis[edge[e].to]) {
			if (dfs(edge[e].to, w))
				return true;
		}
	}
	return false;
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	int u, v, w;
	while (m--) {
		scanf("%d %d %d", &u, &v, &w);
		weight[wCnt++] = w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	sort(weight, weight + wCnt);
	int l = 0, r = wCnt - 1, mid;
	int res = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		memset(vis, 0, sizeof(vis));
		if (dfs(1, weight[mid])) {
			res = weight[mid];
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%d\n", res);
	return 0;
}