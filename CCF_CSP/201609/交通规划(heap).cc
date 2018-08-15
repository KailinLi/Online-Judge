#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
const int MAXM = 100000 + 5;
struct Edge {
    int to;
    int w;
    int next;
};
Edge edge[MAXM << 1];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, int w) {
    edge[++ecnt].to = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}
struct Node {
    int u;
    int d;
};
Node heap[MAXM];
int h_size;
void enq(int d, int u) {
    int idx = ++h_size;
    heap[h_size].d = d;
    heap[h_size].u = u;
    while (idx >> 1 && heap[idx >> 1].d > heap[idx].d) {
        Node tmp = heap[idx >> 1];
        heap[idx >> 1] = heap[idx];
        heap[idx] = tmp;
        idx >>= 1;
    }
}
void deq(int *d, int *u) {
    *d = heap[1].d;
    *u = heap[1].u;
    heap[1] = heap[h_size--];
    int idx = 1;
    while (idx <= h_size) {
        int next = 0;
        if ((idx << 1) <= h_size && heap[idx].d > heap[idx << 1].d)
            next = idx << 1;
        if ((idx << 1 | 1) <= h_size && heap[idx].d > heap[idx << 1 | 1].d
                                        && heap[idx << 1].d > heap[idx << 1 | 1].d)
            next = idx << 1 | 1;
        if (!next) break;
        Node tmp = heap[next];
        heap[next] = heap[idx];
        heap[idx] = tmp;
        idx = next;
    }
}
int d[MAXN];
int vis[MAXN];
int pa[MAXN];
int n, m;
int u, v, w;
int res;
void dijkstra() {
    REP(i, n + 1) d[i] = INF;
    d[1] = 0;
    enq(0, 1);
    while (h_size) {
        Node node;
        deq(&node.d, &node.u);
        if (vis[node.u]) continue;
        vis[node.u] = 1;
        for (int e = head[node.u]; e != 0; e = edge[e].next) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (w + d[node.u] < d[v]) {
                d[v] = w + d[node.u];
                pa[v] = w;
                enq(d[v], v);
            }
            else if (w + d[node.u] == d[v] && w < pa[v])
                pa[v] = w;
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
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dijkstra();
    REP(i, n + 1) res += pa[i];
    printf("%d\n", res); 
    return 0;
}