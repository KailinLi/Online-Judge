#include <stdio.h>
#include <stdlib.h>

const int INF = 0x3f3f3f3f;
#define MAXN 10000 + 5
#define MAXM 100000 + 5
typedef struct edge {
    int to;
    int w;
    int next;
} Edge;
Edge edge[MAXM << 1];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, int w) {
    edge[++ecnt].to = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}
typedef struct node {
    int u;
    int d;
} Node;

int d[MAXN];
int vis[MAXN];
int pa[MAXN];
Node q[MAXM];
int q_cnt;
int n, m;
int u, v, w;
int res;
void dijkstra() {
    int i;
    for (i = 1; i <= n; ++i) d[i] = INF;
    d[1] = 0;
    q[q_cnt].d = 0;
    q[q_cnt++].u = 1;
    while (q_cnt) {
        int i = 0, min = INF, idx;
        for (; i < q_cnt; ++i) if (q[i].d < min) {
            min = q[i].d;
            idx = i;
        }
        --q_cnt;
        Node node = {.u=q[idx].u, .d=q[idx].d};
        q[idx].u = q[q_cnt].u;
        q[idx].d = q[q_cnt].d;
        if (vis[node.u]) continue;
        vis[node.u] = 1;
        int e;
        for (e = head[node.u]; e != 0; e = edge[e].next) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (w + d[node.u] < d[v]) {
                d[v] = w + d[node.u];
                pa[v] = w;
                q[q_cnt].d = d[v];
                q[q_cnt++].u = v;
            }
            else if (w + d[node.u] == d[v] && w < pa[v])
                pa[v] = w;
        }
    }
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dijkstra();
    int i;
    for (i = 1; i <= n; ++i) res += pa[i];
    printf("%d\n", res); 
    return 0;
}