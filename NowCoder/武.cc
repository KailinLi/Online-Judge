#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 10;
struct Edge {
    int to;
    int w;
    int next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int eCnt;
void addEdge(int u, int v, int w) {
    edge[++eCnt].to = v;
    edge[eCnt].w = w;
    edge[eCnt].next = head[u];
    head[u] = eCnt;
}
int N, P, K;
int u, v, w;
int dis[MAXN];
int vis[MAXN];
int KCnt;
struct Ds {
    int v;
    int d;
    Ds(int _v, int _d): v(_v), d(_d) {}
    bool operator< (const Ds& ds) const {
        return d > ds.d;
    }
};
int dijkstra() {
    REP(i, N) dis[i + 1] = INF;
    dis[P] = 0;
    priority_queue<Ds, vector<Ds>> q;
    q.emplace(P, 0);
    while (!q.empty()) {
        Ds current = q.top();
        q.pop();
        if (vis[current.v]) continue;
        vis[current.v] = 1;
        if (KCnt == K) return current.d;
        ++KCnt;
        int &d = current.d;
        for (int e = head[current.v]; e != 0; e = edge[e].next) {
            int &v = edge[e].to;
            if (edge[e].w + d < dis[v]) {
                dis[v] = edge[e].w + d;
                q.emplace(v, dis[v]);
            }
        }
    }
    return -1;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &N, &P, &K);
    REP(i, N - 1) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    printf("%d\n", dijkstra());
    return 0;
}