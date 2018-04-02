#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
struct Edge {
	int to;
	int next;
};
Edge edge[MAXN * MAXN];
int head[MAXN];
int eCnt;
void addEdge(int u, int v) {
	edge[++eCnt].next = head[u];
	edge[eCnt].to = v;
	head[u] = eCnt;
}
int n, u, v;
int vis[MAXN];
int low[MAXN];
int disc[MAXN];
int pa[MAXN];
int ap[MAXN];

int timeS;
void apFind(int u) {
	int childCnt = 0;
	low[u] = disc[u] = ++timeS;
	vis[u] = true;
	for (int e = head[u]; e != 0; e = edge[e].next) {
		int v = edge[e].to;
		if (!vis[v]) {
			++childCnt;
			pa[v] = u;
			apFind(v);
			low[u] = min(low[u], low[v]);
			if (pa[u] == 0 && childCnt > 1)
				ap[u] = 1;
			if (pa[u] != 0 && low[v] >= disc[u])
				ap[u] = 1;
		}
		else if (v != pa[u]) {
			low[u] = min(low[u], disc[v]);
		}
	}
}

int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d", &n) == 1 && n) {
		int u, v;
		timeS = 0;
		eCnt = 0;
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		memset(disc, 0, sizeof(disc));
		memset(pa, 0, sizeof(pa));
		memset(ap, 0, sizeof(ap));
		while (scanf("%d", &u) == 1 && u) {
			while (getchar() != '\n') {
				scanf("%d", &v);
				addEdge(u, v);
				addEdge(v, u);
			}
		}
		apFind(n);
		int res = 0;
		for (int i = 1; i <= n; ++i)
			if (ap[i]) ++res;
		printf("%d\n", res);
	}
	return 0;
}