#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 500 + 10;
const int MAXM = 2500 + 10 + 200;
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

int queue[MAXN];
int h, t;
int deq() {
    int ret = queue[h];
    h = (h + 1) % MAXN;
    return ret;
}
void enq(int u) {
    queue[t] = u;
    t = (t + 1) % MAXN;
}
int n, m, k;
int kase;

int inq[MAXN];
int cnt[MAXN];
int d[MAXN];
int spfa() {
    h = t = 0;
    memset(inq, 0, sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    REP(i, n) d[i + 1] = INF;
    d[1] = 0;
    inq[1] = 1;
    enq(1);
    while (h != t) {
        int u = deq();
        inq[u] = 0;
        for (int e = head[u]; e; e = edge[e].next) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (d[u] < INF && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!inq[v]) {
                    enq(v);
                    inq[v] = 1;
                    if (++cnt[v] > n) return 1;
                }
            }
        }
    }
    return 0;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &kase);
    while (kase--) {
        ecnt = 0;
        memset(head, 0, sizeof(head));
        scanf("%d %d %d", &n, &m, &k);
        int u, v, w;
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        while (k--) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, -w);
        }
        if (spfa()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}