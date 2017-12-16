#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct Edge {
    int v;
    int d;
    Edge(int v, int d): v(v), d(d) {}
};
struct Question {
    int v;
    int time;
    Question(int v, int t): v(v), time(t) {}
};
const int MAXN = 40000 + 10;
int father[MAXN];
int Rank[MAXN];
int visited[MAXN];
int ancestor[MAXN];
int firstFind[MAXN];
vector<Edge> son[MAXN];
vector<Question> q[MAXN];
int Distance[MAXN];
int res[MAXN];
int n, m, u, v, d, i;

int setFind(int u) {
    if (father[u] == u)
        return u;
    father[u] = setFind(father[u]);
    return father[u];
}
void setUnion(int u, int v) {
    u = setFind(u);
    v = setFind(v);
    if (u == v)
        return;
    if (Rank[v] > Rank[u]) {
        father[u] = v;
        Rank[v] += Rank[u];
    }
    else {
        father[v] = u;
        Rank[u] += Rank[v];
    }
}
void LCA(int u, int sumDistance) {
    ancestor[u] = u;
    Distance[u] = sumDistance;
    firstFind[u] = 1;
    for (vector<Edge>::iterator v = son[u].begin(); v != son[u].end(); ++v) {
        if (firstFind[v->v])
            continue;
        LCA(v->v, v->d + sumDistance);
        setUnion(u, v->v);
        ancestor[setFind(u)] = u;
    }
    visited[u] = 1;
    for (vector<Question>::iterator v = q[u].begin(); v != q[u].end(); ++v) {
        if (visited[v->v]) {
            res[v->time] = Distance[u] + Distance[v->v] - 
                            (Distance[ancestor[setFind(v->v)]] << 1);
        }
    }
}

int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) == 2) {
        for (i = 1; i <= n; ++i) {
            father[i] = i;
            son[i].clear();
            q[i].clear();
        }
        memset(Rank, 1, sizeof(int) * n + 1);
        memset(visited, false, sizeof(int) * n + 1);
        memset(firstFind, 0, sizeof(int) * n + 1);
        char tmp[10];
        while (m--) {
            scanf("%d %d %d %s", &u, &v, &d, tmp);
            son[u].push_back(Edge(v, d));
            son[v].push_back(Edge(u, d));
        }
        scanf("%d", &m);
        for (i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            q[u].push_back(Question(v, i));
            q[v].push_back(Question(u, i));
        }
        LCA(1, 0);
        for (i = 0; i < m; ++i) {
            printf("%d\n", res[i]);
        }
    }
}