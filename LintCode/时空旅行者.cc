#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 5;
int line[MAXN];
int vis[MAXN];
int t, n, s, k;
int kase;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d %d %d", &n, &s, &k);
		REP(i, n + 1) scanf("%d", line + i);
		vis[k] = 1;
		int layer = 0;
		queue<int> q;
		q.push(k);
		int flag = true;
		while (!q.empty() && flag) {
			int size = q.size();
			while (size-- && flag) {
				int c = q.front();
				q.pop();
				if (c == s)
					flag = false;
				if (c > 0 && !vis[c - 1] && !line[c - 1]) q.push(c - 1);
				if (c < n && !vis[c + 1] && !line[c + 1]) q.push(c + 1);
				if (c > 1 && !vis[c - 2] && line[c - 2]) q.push(c - 2);
				if (c < n - 1 && !vis[c + 2] && line[c + 2]) q.push(c + 2);
				if (c && !(c % 2) && !vis[c >> 1] && line[c >> 1]) q.push(c >> 1);
			}
			++layer;
		}
		printf("Case #%d: ", ++kase);
		printf("%d\n", flag ? -1 : layer - 1);
	}
	return 0;
}