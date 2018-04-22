#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 10;
struct Edge {
    int to;
    int next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int eCnt;
void addEdge(int u, int v) {
    edge[++eCnt].to = v;
    edge[eCnt].next = head[u];
    head[u] = eCnt;
}
int T, n, r;
int u, v;
int vis[MAXN];
bool dfs(int u) {
    vis[u] = 1;
    bool res = false;
    for (int e = head[u]; e != 0; e = edge[e].next) {
        if (!vis[edge[e].to] && !dfs(edge[e].to)) {
            res = true;
            break;
        }
    }
    return res;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &r);
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        eCnt = 0;
        REP(i, n - 1) {
            scanf("%d %d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        if (!dfs(r)) printf("Dui\n");
        else printf("Gen\n");
    }
    return 0;
}