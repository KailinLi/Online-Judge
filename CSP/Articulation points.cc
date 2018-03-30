#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int timeS;
void apFind(int u, vector<bool> &vis, vector<int> &low, 
		vector<int> &disc, vector<int> &pa, vector<vector<int> > &graph, int n, vector<bool> &ap) {
	int childCnt = 0;
	low[u] = disc[u] = ++timeS;
	vis[u] = true;
	for (int v = 1; v <= n; ++v) {
		if (v == u || !graph[u][v]) continue;
		if (!vis[v]) {
			++childCnt;
			pa[v] = u;
			apFind(v, vis, low, disc, pa, graph, n, ap);
			low[u] = min(low[u], low[v]);
			if (pa[u] == 0 && childCnt > 1)
				ap[u] = true;
			if (pa[u] != 0 && low[v] >= disc[u])
				ap[u] = true;
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
	int n;
	bool find = false;
	cin >> n;	//size of graph
	vector<bool> vis(n + 1, false);
	vector<int> low(n + 1);
	vector<int> disc(n + 1);
	vector<int> pa(n + 1, 0);
	vector<bool> ap(n + 1, false);
	vector<vector<int> > graph(n + 1, vector<int> (n + 1));
	for (int i = 1; i <= n; ++i) {
		int tmp;
		for (int j = 1; j <= n; ++j) {
			cin >> tmp;
			graph[i][j] = tmp;
		}
	}
	for (int u = 1; u <= n; ++u)
		if (!vis[u])
			apFind(u, vis, low, disc, pa, graph, n, ap);
	for (int u = 1; u <= n; ++u)
		if (ap[u]) {
			find = true;
			cout << u - 1 << endl;	// number from 0 to n - 1
		}
	if (!find) cout << "No find!" << endl;
	return 0;
}