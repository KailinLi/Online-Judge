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
Node q[MAXM];
int h, t;
void enq(int d, int u) {
    q[t].d = d;
    q[t].u = u;
    t = (t + 1) % MAXN;
}
void deq(int *d, int *u) {
    *d = q[h].d;
    *u = q[h].u;
    h = (h + 1) % MAXN;
}
int isempty() {
    return h == t;
}

int d[MAXN];
int vis_cnt[MAXN];
int pa[MAXN];
int inq[MAXN];
int n, m;
int u, v, w;
int res;

int spfa() {
    REP(i, n + 1) d[i] = INF;
    vis_cnt[1] = inq[1] = 1;
    enq(0, 1);
    d[1] = 0;
    while (!isempty()) {
        int u, dis;
        deq(&dis, &u);
        inq[u] = 0;
        for (int e = head[u]; e != 0; e = edge[e].next) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pa[v] = w;
                if (!inq[v]) {
                    if (vis_cnt[v]++ > n) return 1;
                    inq[v] = 1;
                    enq(d[v], v);
                }
            }
            else if (d[u] + w == d[v] && w < pa[v])
                pa[v] = w;
        }
    }
    return 0;
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
    spfa();
    REP(i, n + 1)
        res += pa[i];
    printf("%d\n", res); 
    return 0;
}