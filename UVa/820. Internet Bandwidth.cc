#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 10;
const int MAXM = MAXN * MAXN;
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
int n;
int a[MAXN];
int pa[MAXN];
int maxflow(int s, int t) {
    int flow = 0;
    queue<int> q;
    while (true) {
        memset(a, 0, sizeof(a));
        while (!q.empty()) q.pop();
        a[s] = INF;
        q.push(s);
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
            if (a[t]) break;
        }
        if (!a[t]) break;
        for (int u = t; u != 1; u = edge[pa[u]].from) {
            edge[pa[u]].f += a[t];
            edge[pa[u] ^ 1].f -= a[t];
        }
        flow += a[t];
    }
    return flow;
}
int s, t, c;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) == 1 && n) {
        ecnt = 0;
        memset(head, -1, sizeof(head));
        scanf("%d %d %d", &s, &t, &c);
        int u, v, f;
        while (c--) {
            scanf("%d %d %d", &u, &v, &f);
            add_edge(u, v, f, 0);
            add_edge(v, u, -f, 0);
        }
        printf("Network %d\nThe bandwidth is %d.\n", ++kase, maxflow(s, t));
    }
    return 0;
}