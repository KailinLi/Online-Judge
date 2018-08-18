#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
const int MAXM = 10000 + 5;

int n, m;
struct Edge {
    int to;
    int next;
};
Edge edge[MAXM];
int head[MAXN];
int ecnt;
void add_edge(int u, int v) {
    edge[++ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}
int u, v;
int res;
int connect[MAXN][MAXN];
int vis[MAXN];
void dfs(int u, int cur) {
    vis[u] = 1;
    connect[u][cur] = connect[cur][u] = 1;
    for (int e = head[u]; e; e = edge[e].next) {
        if (vis[edge[e].to]) continue;
        dfs(edge[e].to, cur);
    }
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    REP(i, m) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    REP(i, n) {
        memset(vis, 0, sizeof(vis));
        dfs(i + 1, i + 1);
    }
    REP(i, n) {
        int flg = 1;
        REP(j, n) {
            if (!connect[i + 1][j + 1]) {
                flg = 0;
                break;
            }
        }
        if (flg) ++res;
    }
    printf("%d\n", res);
    return 0;
}