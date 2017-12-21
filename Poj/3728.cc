#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 50000 + 5;
int father[MAXN];
int Rank[MAXN];
int visited[MAXN];
int ancestor[MAXN];

struct Edge {
    int to;
    int next;
};
Edge edge[MAXN * 2];
int head[MAXN];
int edgeCnt;
void addEdge(int u, int v) {
    edge[++edgeCnt].to = v;
    edge[edgeCnt].next = head[u];
    head[u] = edgeCnt;
}

struct Question {
    int to;
    int next;
    int from;
};
Question question[MAXN * 2];
int qHead[MAXN];
int qCnt;
void addQustion(int u, int v, int f) {
    question[++qCnt].to = v;
    question[qCnt].next = qHead[u];
    question[qCnt].from = f;
    qHead[u] = qCnt;
}

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

int res[MAXN];
int cost[MAXN];
int pathCost[MAXN];

void LCA(int u, int father) {
    ancestor[u] = u;
    for (int i = head[u]; i != 0; i = edge[i].next) {
        if (edge[i].to == father)
            continue;
        LCA(edge[i].to, u);
        setUnion(u, edge[i].to);
        ancestor[setFind(u)] = u;
    }
    visited[u] = 1;
    for (int i = qHead[u]; i != 0; i = question[i].next) {
        if (visited[question[i].to]) {
            int questionID = (i + 1) >> 1;
            int from = question[i].from;
            int to = (from == u) ? question[i].to : u;
            res[questionID] = pathCost[to] - pathCost[from];
            // printf("%d\n", ancestor[setFind(question[i].to)]);
        }
    }
}

void dfs(int u, int sumCost, int father) {
    pathCost[u] = cost[u] - sumCost;
    for (int i = head[u]; i != 0; i = edge[i].next) {
        if (edge[i].to == father)
            continue;
        dfs(edge[i].to, cost[u] - pathCost[u], u);
    }
}

int n;
int w, u, v, q;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) == 1) {
        memset(qHead, 0, sizeof(qHead));
        memset(head, 0, sizeof(head));
        qCnt = 0;
        edgeCnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
            Rank[i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", cost + i);
        }
        for (int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i) {
            scanf("%d %d", &u, &v);
            addQustion(u, v, u);
            addQustion(v, u, u);
        }
        dfs(1, 0, -1);
        LCA(1, -1);
        for (int i = 1; i <= q; ++i) {
            printf("%d\n", (res[i] < 0) ? 0 : res[i]);
        }
    }
}