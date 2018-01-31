#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const int MAXN = 510;
const int MAXM = 200010;
using namespace std;
struct Edge {
    int to;
    int type;
    int weight;
    int next;
};
Edge edge[MAXM];
int head[MAXM];
int edgeCnt;
void addEdge(int u, int v, int t, int w) {
    edge[++edgeCnt].to = v;
    edge[edgeCnt].type = t;
    edge[edgeCnt].weight = w;
    edge[edgeCnt].next = head[u];
    head[u] = edgeCnt;
}
struct Node {
    int u;
    int path;
    int tired;
    Node(int _u, int _path, int _tired): u(_u), path(_path), tired(_tired) {}
};
bool cmp(const Node& lhs, const Node& rhs) {
    return (lhs.path > rhs.path) || (lhs.path == rhs.path && lhs.tired > rhs.tired);
}
int d[MAXN];
int tire[MAXN];
int visited[MAXN];
void dijkstra(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        d[i] = 0x3f3f3f3f;
    }
    priority_queue<Node, vector<Node>, bool (*)(const Node&, const Node&)> q(cmp);
    q.push(Node(s, 0, 0));
    d[s] = 0;
    while (!q.empty()) {
        Node current = q.top();
        q.pop();
        if (current.u == t) return;
        // if (visited[current.u]) continue;
        visited[current.u] = 1;
        for (int e = head[current.u]; e != 0; e = edge[e].next) {
            // if (visited[edge[e].to]) continue;
            int cost = current.path;
            int tired = 0;
            if (edge[e].type) {
                tired = current.tired + edge[e].weight;
                cost -= current.tired * current.tired;
                cost += (current.tired + edge[e].weight) * (current.tired + edge[e].weight);
            }
            else {
                cost += edge[e].weight;
            }
            if (d[edge[e].to] > cost || (d[edge[e].to] == cost && tire[edge[e].to] > tired)) {
                d[edge[e].to] = cost;
                tire[edge[e].to] = tired;
                q.push(Node(edge[e].to, cost, tired));
            }
        }
    }
}
int n, m;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    int t, u, v, w;
    while (m--) {
        scanf("%d %d %d %d", &t, &u, &v, &w);
        addEdge(u, v, t, w);
        addEdge(v, u, t, w);
    }
    dijkstra(1, n);
    printf("%d\n", d[n]);
}