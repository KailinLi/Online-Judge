#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
const int MAXM = 100000 + 5;
struct Edge {
	int to;
	int next;
};
Edge edge[MAXM];
int head[MAXN];
int eCnt;
void addEdge(int u, int v) {
	edge[++eCnt].to = v;
	edge[eCnt].next = head[u];
	head[u] = eCnt;
}
int pre[MAXN], lowlink[MAXN], sccno[MAXN], dfs_clock, scc_cnt;
int s[MAXN];
int sp;
int n, m;
// add
int scc_res[MAXN];
void dfs(int u) {
	pre[u] = lowlink[u] = ++dfs_clock;
	s[sp++] = u;
	for (int e = head[u]; e != 0; e = edge[e].next) {
		int v = edge[e].to;
		if (!pre[v]) {
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if (!sccno[v]) {
			lowlink[u] = min(lowlink[u], pre[v]);
		}
	}
	if (lowlink[u] == pre[u]) {
		++scc_cnt;
		while (true) {
			int x = s[--sp];
			sccno[x] = scc_cnt;
			if (x == u) break;
		}
	}
}
void find_scc(int n) {
	dfs_clock = scc_cnt = 0;
	memset(sccno, 0, sizeof(sccno));
	memset(pre, 0, sizeof(pre));
	REP(i, n)
		if(!pre[i]) dfs(i);
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	int u, v;
	while (m--) {
		scanf("%d %d", &u, &v);
		addEdge(u, v);
	}
	find_scc(n);
	int sum = 0;
	REP(i, n + 1)
		++scc_res[sccno[i]];
	for (int i = 1; i <= scc_cnt; ++i) {
		sum += (scc_res[i] * (scc_res[i] - 1)) >> 1;
	}
	printf("%d\n", sum);
	return 0;
}