#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 15 + 5;
const int MAXM = 1000 + 10;
struct Edge {
    int from;
    int to;
    int c;
    int f;
    int next;
};
Edge edge[MAXM << 1];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, int c, int f) {
    edge[ecnt].from = u;
    edge[ecnt].to = v;
    edge[ecnt].c = c;
    edge[ecnt].f = f;
    edge[ecnt].next = head[u];
    head[u] = ecnt++;
}

int kase;
int t, m, n;
int a[MAXN];
int pa[MAXN];
int maxflow() {
    int flow = 0;
    queue<int> q;
    while (true) {
        memset(a, 0, sizeof(a));
        while (!q.empty()) q.pop();
        a[1] = INF;
        q.push(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int e = head[u]; e != -1; e = edge[e].next) {
                int v = edge[e].to;
                if (!a[v] && edge[e].c > edge[e].f) {
                    pa[v] = e;
                    a[v] = min(a[u], edge[e].c - edge[e].f);
                    q.push(v);
                }
            }
            if (a[n]) break;
        }
        if (!a[n]) break;
        for (int u = n; u != 1; u = edge[pa[u]].from) {
            edge[pa[u]].f += a[n];
            edge[pa[u] ^ 1].f -= a[n];
        }
        flow += a[n];
    }
    return flow;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        ecnt = 0;
        memset(head, -1, sizeof(head));
        int u, v, f;
        while (m--) {
            scanf("%d %d %d", &u, &v, &f);
            add_edge(u, v, f, 0);
            add_edge(v, u, 0, 0);
        }
        printf("Case %d: %d\n", ++kase, maxflow());
    }
    return 0;
}