#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 5;
const int MAXM = 200000 + 5;
struct Edge {
    int to;
    int t;
    int next;
};
Edge edge[MAXM << 1];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, int t) {
    edge[++ecnt].to = v;
    edge[ecnt].t = t;
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
int n, m;
int u, v, t;
void dijkstra() {
    REP(i, n) d[i + 1] = INF;
    d[1] = 0;
    enq(0, 1);
    while (h_size) {
        deq(&t, &u);
        if (u == n) break;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int e = head[u]; e; e = edge[e].next) {
            if (vis[edge[e].to]) continue;
            if (max(edge[e].t, d[u]) < d[edge[e].to]) {
                d[edge[e].to] = max(edge[e].t, d[u]);
                enq(d[edge[e].to], edge[e].to);
            }
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
        scanf("%d %d %d", &u, &v, &t);
        add_edge(u, v, t);
        add_edge(v, u, t);
    }
    dijkstra();
    printf("%d\n", d[n]);
    return 0;
}