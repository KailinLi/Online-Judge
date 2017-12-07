#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 5;
vector<pair<int, int> > adj[MAXN];
int p[MAXN];
int d[MAXN];
int visited[MAXN];
struct Distance {
	int u;
	int d;
	Distance(int u, int d): u(u), d(d) {}
};
bool cmp(const Distance& lhs, const Distance& rhs) {
	return lhs.d > rhs.d;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back(make_pair(v, d));
		adj[v].push_back(make_pair(u, d));
	}
	memset(d, 0x7f, sizeof(d));
	priority_queue<Distance, vector<Distance>,
				   bool (*)(const Distance &lhs, const Distance &rhs)>
		q(cmp);
	d[1] = 0;
	q.push(Distance(1, 0));
	while (!q.empty()) {
		Distance current = q.top();
		q.pop();
		if(visited[current.u])
			continue;
		visited[current.u] = 1;
		for (vector<pair<int, int> >::iterator i = adj[current.u].begin();
				i != adj[current.u].end(); ++i) {
			if (i->second + d[current.u] < d[i->first]) {
				d[i->first] = i->second + d[current.u];
				p[i->first] = i->second;
				q.push(Distance(i->first, i->second + d[current.u]));
			}
			else if (i->second + d[current.u] == d[i->first]) {
				p[i->first] = min(i->second, p[i->first]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		// cout << p[i] << endl;
		res += p[i];
	}
	cout << res << endl;
}