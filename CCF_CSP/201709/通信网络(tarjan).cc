#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
const int MAXM = 10000 + 5;

struct Edge {
    int to;
    int next;
};
Edge edge[MAXM];
Edge redge[MAXM];
int head[MAXN];
int rhead[MAXN];
int ecnt;
void addEdge(int u, int v) {
    edge[++ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
    redge[ecnt].to = u;
    redge[ecnt].next = rhead[v];
    rhead[v] = ecnt;
}

int stack[MAXN];
int pos;
int in_stack[MAXN];
int dfn[MAXN];
int low[MAXN];
int idx;
int n, m, x, y;
int label[MAXN];
int core[MAXN];
int core_cnt;
int pa[MAXN];
int child[MAXN];
int vis[MAXN];
int res;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    stack[pos++] = u;
    in_stack[u] = 1;
    for (int e = head[u]; e != 0; e = edge[e].next) {
        int v = edge[e].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        int v;
        do {
            v = stack[--pos];
            in_stack[v] = 0;
            label[v] = core_cnt;
        } while (v != u);
        core[core_cnt++] = v;
    }
}

void dfs(int u, int l, int *cnt, int r) {
    if (label[u] != l) ++cnt[u];
    if (r) {
        for (int e = rhead[u]; e; e = redge[e].next) {
            int v = redge[e].to;
            if (vis[v]) continue;
            vis[v] = 1;
            dfs(v, l, cnt, r);
        }
    }
    else {
        for (int e = head[u]; e; e = edge[e].next) {
            int v = edge[e].to;
            if (vis[v]) continue;
            vis[v] = 1;
            dfs(v, l, cnt, r);
        }
    }
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &x, &y);
        addEdge(x, y);
    }
    REP(i, n) if (!dfn[i + 1]) tarjan(i + 1);
    REP(k, 2) REP(i, core_cnt) {
        memset(vis, 0, sizeof(vis));
        int u = core[i];
        vis[u] = 1;
        if (k)
            dfs(u, label[u], pa, 0);
        else
            dfs(u, label[u], child, 1);
    }
    REP(i, n) {
        if (pa[i + 1] + child[i + 1] + 1 == core_cnt) ++res;
    }
    printf("%d\n", res);
    return 0;
}