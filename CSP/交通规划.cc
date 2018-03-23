#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
const int MAXM = 100000 + 5;
struct Node {
	int u;
	int d;
	bool operator< (const Node & rhs) const {
		return d > rhs.d;
	}
	Node(int _u, int _d): u(_u), d(_d) {}
};
int n, m;
struct Edge {
	int to;
	int next;
	int w;
};
Edge edge[MAXM << 1];
int head[MAXN];
int eCnt;
void addEdge(int u, int v, int w) {
	edge[++eCnt].to = v;
	edge[eCnt].w = w;
	edge[eCnt].next = head[u];
	head[u] = eCnt;
}
int d[MAXN];
int vis[MAXN];
int pCost[MAXN];
void dijkstra(int s) {
	priority_queue<Node, vector<Node> >q;
	REP(i, n + 1) d[i] = INF;
	d[s] = 0;
	q.push(Node(s, 0));
	while (!q.empty()) {
		Node p = q.top();
		q.pop();
		if (vis[p.u]) continue;
		vis[p.u] = 1;
		for (int e = head[p.u]; e != 0; e = edge[e].next) {
			int cost = p.d + edge[e].w;
			if (cost < d[edge[e].to]) {
				d[edge[e].to] = cost;
				pCost[edge[e].to] = edge[e].w;
				q.push(Node(edge[e].to, d[edge[e].to]));
			}
			else if (cost == d[edge[e].to] && pCost[edge[e].to] > edge[e].w) {
				pCost[edge[e].to] = edge[e].w;
			}
		}
	}
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
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	dijkstra(1);
	int res = 0;
	REP(i, n) {
		res += pCost[i + 1];
	}
	printf("%d\n", res);
	return 0;
}