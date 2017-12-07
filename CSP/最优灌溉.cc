#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000 + 5;
struct UnionFind {
	int parent;
	int rank;
};
UnionFind ufset[MAXN];
struct Edge {
	int u;
	int v;
	int d;
	Edge(int u, int v, int d): u(u), v(v), d(d) {}
};
bool cmp(const Edge& lhs, const Edge& rhs) {
	return lhs.d > rhs.d;
}
int setFind(int i) {
	if (ufset[i].parent != i) {
		ufset[i].parent = setFind(ufset[i].parent);
	}
	return ufset[i].parent;
}
void setUnion(int xroot, int yroot) {
	if (ufset[xroot].rank < ufset[yroot].rank) {
		ufset[xroot].parent = yroot;
	}
	else if (ufset[xroot].rank > ufset[yroot].rank) {
		ufset[yroot].parent = xroot;
	}
	else {
		ufset[yroot].parent = xroot;
		++ufset[xroot].rank;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	int res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		ufset[i].parent = i;
	}
	priority_queue<Edge, vector<Edge>, bool (*)(const Edge &lhs, const Edge &rhs)> q(cmp);
	while (m--)
	{
		int u, v, d;
		cin >> u >> v >> d;
		q.push(Edge(u, v, d));
	}
	while (!q.empty()) {
		Edge current = q.top();
		q.pop();
		int xroot = setFind(current.u);
		int yroot = setFind(current.v);
		if (xroot == yroot)
			continue;
		res += current.d;
		setUnion(xroot, yroot);
	}
	cout << res << endl;
}