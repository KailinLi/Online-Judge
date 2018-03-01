#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100 + 5;
const int MAXM = 6000;
struct Edge {
	int to;
	int next;
};
Edge edge[MAXM];
int edgeCnt;
int head[MAXN];
int isVisited[MAXN];
int res[MAXN];
int cnt;
void addEdge(int u, int v) {
	edge[++edgeCnt].next = head[u];
	edge[edgeCnt].to = v;
	head[u] = edgeCnt;
}
int n, m;
bool DFS(int u) {
	isVisited[u] = -1;
	for (int e = head[u]; e != 0; e = edge[e].next) {
		if (isVisited[edge[e].to] == -1)
			return false;
		if (!isVisited[edge[e].to] && !DFS(edge[e].to))
			return false;
	}
	isVisited[u] = 1;
	res[--cnt] = u;
	return true;
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while(scanf("%d %d", &n, &m) == 2 && n != 0) {
		int u, v;
		edgeCnt = 0;
		memset(isVisited, 0, sizeof(isVisited));
		memset(head, 0, sizeof(head));
		while (m--) {
			scanf("%d %d", &u, &v);
			addEdge(u, v);
		}
		cnt = n;
		for (int u = 1; u <= n; ++u) {
			if (!isVisited[u])
				DFS(u);
		}
		int tmpCnt = 0;
		for (int i = 0; i < n; ++i) {
			if (tmpCnt++) printf(" ");
			printf("%d", res[i]);
		}
		printf("\n");
	}
}