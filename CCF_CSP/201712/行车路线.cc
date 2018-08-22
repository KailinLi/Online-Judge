#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f;
const int MAXN = 500 + 5;
const int MAXM = 100000 + 5;
struct Edge {
    int to;
    int type;
    int w;
    int next;
};
Edge edge[MAXM << 1];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, int t, int w) {
    edge[++ecnt].to = v;
    edge[ecnt].type = t;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}
int n, m;
int u, v, w, t;
int vis[MAXN];
LL d[MAXN];
struct Node {
    int u;
    LL d;
    int l;
    bool operator< (const Node &rhs) const {
        return d > rhs.d || (d == rhs.d && l > rhs.l);
    }
    Node(int u, LL d, int l): u(u), d(d), l(l) {}
};
void dijkstra (void) {
    REP(i, n) d[i] = INF;
    d[0] = 0;
    priority_queue<Node, vector<Node> > q;
    q.push(Node(0, 0, 0));
    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        if (vis[cur.u]) continue;
        if (cur.u == n - 1) break;
        vis[cur.u] = 1;
        for (int e = head[cur.u]; e; e = edge[e].next) {
            int v = edge[e].to;
            if (edge[e].type) {
                LL cost = cur.d - (LL)pow(cur.l, 2) + (LL)pow(cur.l + edge[e].w, 2);
                if (cost < d[v]) {
                    d[v] = cost;
                    q.push(Node(v, cost, cur.l + edge[e].w));
                }
            }
            else {
                LL cost = cur.d + edge[e].w;
                if (cost < d[v]) {
                    d[v] = cost;
                    q.push(Node(v, cost, 0));
                }
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
        scanf("%d %d %d %d", &t, &u, &v, &w);
        add_edge(u - 1, v - 1, t, w);
        add_edge(v - 1, u - 1, t, w);
    }
    dijkstra();
    printf("%lld\n", d[n - 1]);
    return 0;
}