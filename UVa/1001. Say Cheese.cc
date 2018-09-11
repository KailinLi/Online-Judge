#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 10;
struct Edge {
    int to;
    double w;
    int next;
};
Edge edge[(MAXN * MAXN) << 1];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, double w) {
    edge[++ecnt].to = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}
int n;
struct Hole {
    int x;
    int y;
    int z;
    double r;
};
Hole hole[MAXN];

int vis[MAXN];
double dis[MAXN];
double dijkstra(int s, int t) {
    REP(i, n) dis[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        pair<int, int> p = q.top(); q.pop();
        int u = p.second;
        if (vis[u]) continue;
        if (u == t) break;
        vis[u] = 1;
        for (int e = head[u]; e; e = edge[e].next) {
            int v = edge[e].to;
            double w = edge[e].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
    return dis[t];
}
int kase;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) == 1 && n != -1) {
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        ecnt = 0;
        REP(i, n + 2) {
            scanf("%d %d %d", &hole[i].x, &hole[i].y, &hole[i].z);
            if (i < n) scanf("%lf", &hole[i].r);
            else hole[i].r = 0.0;
        }
        n += 2;
        REP(i, n) for (int j = i + 1; j < n; ++j) {
            double dis = max(0.0, sqrt(pow(hole[i].x - hole[j].x, 2) + 
                pow(hole[i].y - hole[j].y, 2) + pow(hole[i].z - hole[j].z, 2)) - hole[i].r - hole[j].r);
            add_edge(i, j, dis);
            add_edge(j, i, dis);
        }
        printf("Cheese %d: Travel time = %d sec\n", ++kase, (int)(dijkstra(n - 2, n - 1) * 10 + 0.5));
    }
    return 0;
}