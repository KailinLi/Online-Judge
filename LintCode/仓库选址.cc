#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 5;
int town[MAXN];
struct Edge {
	int to;
	int w;
	int next;
};
Edge edge[MAXN << 1];
int eCnt;
int head[MAXN];
void addEdge(int u, int v, int w) {
	edge[++eCnt].next = head[u];
	edge[eCnt].to = v;
	edge[eCnt].w = w;
	head[u] = eCnt;
}
int n, m, k, t;
int u, v, w;
int kase;
int vis[MAXN];
int d[MAXN];
struct Point {
	int to;
	int d;
	bool operator< (const Point& rhs) const {
		return d > rhs.d;
	}
	Point(int _to, int _d): to(_to), d(_d) {}
};
void dijkstra(int s) {
	priority_queue<Point, vector<Point>> q;
	q.push(Point(s, 0));
	d[s] = 0;
	while (!q.empty()) {
		Point current = q.top();
		q.pop();
		if (vis[current.to]) continue;
		if (current.to == n) return;
		for (int e = head[current.to]; e != 0; e = edge[e].next) {
			if (vis[edge[e].to]) continue;
			if (d[current.to] + edge[e].w < d[edge[e].to]) {
				d[edge[e].to] = d[current.to] + edge[e].w;
				q.push(Point(edge[e].to, d[edge[e].to]));
			}
		}
	}
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		memset(head, 0, sizeof(head));
		memset(town, 0, sizeof(town));
		memset(vis, 0, sizeof(vis));
		scanf("%d %d %d", &n, &m, &k);
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			addEdge(u + 1, v + 1, w);
			addEdge(v + 1, u + 1, w);
		}
		while (k--) {
			scanf("%d", &u);
			town[u + 1] = 1;
		}
		for (int i = 2; i <= n + 1; ++i) {
			if (town[i]) {
				addEdge(1, i, 0); addEdge(i, 1, 0);
			}
			else {
				addEdge(n + 2, i, 0); addEdge(i, n + 2, 0);
			}
		}
		n += 2;
		REP(i, n + 1) d[i] = INF;
		dijkstra(1);
		printf("Case #%d: ", ++kase);
		printf("%d\n", d[n] == INF ? -1 : d[n]);
	}
	return 0;
}