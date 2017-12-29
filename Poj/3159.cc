#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 30000 + 10;
const int MAXM = 150000 + 10;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to;
    int w;
    int next;
};
Edge edge[MAXM];
int head[MAXN];
int cnt;
inline void addEdge(int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
struct Pair {
    int v;
    int w;
    Pair(int _v, int _w): v(_v), w(_w) {}
};
struct Cmp {
    bool operator() (const Pair& lhs, const Pair& rhs) {
        return lhs.w > rhs.w;
    }
};
int n, m;
int u, v, w;
int d[MAXN];
bool visited[MAXN];
void dijkstra(int s) {
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
        visited[i] = false;
    }
    priority_queue<Pair, vector<Pair>, Cmp>q;
    q.push(Pair(s, 0));
    visited[s] = true;
    d[s] = 0;
    while (!q.empty()) {
        Pair current = q.top();
        if (current.v == n)
            return;
        q.pop();
        visited[current.v] = true;
        for (int i = head[current.v]; i != 0; i = edge[i].next) {
            if (visited[edge[i].to])
                continue;
            if (d[current.v] + edge[i].w < d[edge[i].to]) {
                d[edge[i].to] = d[current.v] + edge[i].w;
                q.push(Pair(edge[i].to, d[edge[i].to]));
            }
        }
    }
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    dijkstra(1);
    printf("%d\n", d[n]);
}