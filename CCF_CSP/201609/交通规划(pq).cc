#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

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
    bool operator< (const Node &rhs) const {
        return d > rhs.d;
    }
    Node(int u, int d): u(u), d(d) {}
};
int d[MAXN];
int vis[MAXN];
int pa[MAXN];
int n, m;
int u, v, w;
int res;
void dijkstra() {
    priority_queue<Node, vector<Node> > q;
    REP(i, n + 1) d[i] = INF;
    d[1] = 0;
    q.push(Node(1, 0));
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        if (vis[node.u]) continue;
        vis[node.u] = 1;
        for (int e = head[node.u]; e != 0; e = edge[e].next) {
            int v = edge[e].to;
            int w = edge[e].w;
            if (w + d[node.u] < d[v]) {
                d[v] = w + d[node.u];
                pa[v] = w;
                q.push(Node(v, d[v]));
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