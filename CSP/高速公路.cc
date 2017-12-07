#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 5;
vector<int> adj[MAXN];
int n, m;
int DFN[MAXN];
int S[MAXN];
int is_inStack[MAXN];
int sp;
int id;
int Low[MAXN];
int res;
void tarjan(int u) {
	DFN[u] = ++id;
	Low[u] = id;
	S[sp++] = u;
	is_inStack[u] = 1;
	for (vector<int>::iterator i = adj[u].begin(); i != adj[u].end(); ++i) {
		if (!DFN[*i]) {
			tarjan(*i);
			Low[u] = min(Low[u], Low[*i]);
		}
		else if (is_inStack[*i]) {
			Low[u] = min(Low[u], DFN[*i]);
		}
	}
	if (Low[u] == DFN[u]) {
		int cnt = 0;
		int current;
		do {
			current = S[--sp];
			is_inStack[current] = 0;
			// cout << current << " ";
			++cnt;
		} while (current != u);
		// cout << endl;
		res += ((cnt - 1) * cnt) / 2;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	sp = 1;
	for (int i = 1; i <= n; ++i) {
		if (!DFN[i]) {
			tarjan(i);
		}
	}
	cout << res << endl;
}