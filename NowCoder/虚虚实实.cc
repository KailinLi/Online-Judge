#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 30 + 5;
struct Edge {
    int to;
    int next;
};
Edge edge[MAXN * MAXN];
int head[MAXN];
int eCnt;
void addEdge(int u, int v) {
    edge[++eCnt].to = v;
    edge[eCnt].next = head[u];
    head[u] = eCnt;
}
int d[MAXN];
int T, n, m;
int u, v;
int vis[MAXN];
int pCnt;
void dfs(int u) {
    ++pCnt;
    vis[u] = 1;
    for (int e = head[u]; e != 0; e = edge[e].next) {
        int v = edge[e].to;
        if (!vis[v]) dfs(v);
    }
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        memset(d, 0, sizeof(d));
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
        eCnt = 0;
        pCnt = 0;
        while (m--) {
            scanf("%d %d", &u, &v);
            if (u == v) continue;
            ++d[u];
            ++d[v];
            addEdge(u, v);
            addEdge(v, u);
        }
        int oddCnt = 0;
        REP(i, n) if (d[i + 1] % 2) ++oddCnt;
        if (oddCnt == 2 || !oddCnt) {
            dfs(1);
            if (pCnt == n) printf("Zhen\n");
            else printf("Xun\n");
        }
        else printf("Xun\n");
    }
    return 0;
}