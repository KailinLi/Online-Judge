#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50000 + 5;
const int MAXV = 16;
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
int depth[MAXN];
int dpMax[MAXV][MAXN];
int dpMin[MAXV][MAXN];
int dpUp[MAXV][MAXN];
int dpDown[MAXV][MAXN];
int parent[MAXV][MAXN];

int Up(int u, int k, int &minPrice) {
    minPrice = 0x3f3f3f3f;
    int maxProfit = 0;
    int prevMinPrice = 0x3f3f3f3f;
    for (int i = MAXV - 1; i >= 0; --i) {
        if (k >> i & 1) {
            minPrice = min(minPrice, dpMin[i][u]);
            maxProfit = max(maxProfit, max(dpUp[i][u], dpMax[i][u] - prevMinPrice));
            prevMinPrice = min(prevMinPrice, dpMin[i][u]);
            u = parent[i][u];
        }
    }
    return maxProfit;
}
int Down(int u, int k, int &maxPrice) {
    maxPrice = 0;
    int maxProfit = 0;
    int prevMaxPrice = 0;
    for (int i = MAXV - 1; i >= 0; --i) {
        if (k >> i & 1) {
            maxPrice = max(maxPrice, dpMax[i][u]);
            maxProfit = max(maxProfit, max(dpDown[i][u], prevMaxPrice - dpMin[i][u]));
            prevMaxPrice = max(prevMaxPrice, dpMax[i][u]);
            u = parent[i][u];
        }
    }
    return maxProfit;
}
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
            int lca = ancestor[setFind(question[i].to)];
            int maxPrice, minPrice;
            int upProfit = Up(from, depth[from] - depth[lca], minPrice);
            int downProfit = Down(to, depth[to] - depth[lca], maxPrice);
            res[questionID] = max(max(upProfit, downProfit), maxPrice - minPrice);
        }
    }
}

void dfs(int u, int d, int father) {
    parent[0][u] = father;
    depth[u] = d;
    dpUp[0][u] = max(cost[father] - cost[u], 0);
    dpDown[0][u] = max(cost[u] - cost[father], 0);
    dpMax[0][u] = max(cost[u], cost[father]);
    dpMin[0][u] = min(cost[u], cost[father]);
    for (int i = head[u]; i != 0; i = edge[i].next) {
        if (edge[i].to == father)
            continue;
        dfs(edge[i].to, d + 1, u);
    }
}
void init(int u) {
    memset(dpMax, 0, sizeof(dpMax));
    memset(dpMin, 0x3f, sizeof(dpMin));
    dfs(1, 0, -1);
    for (int k = 0; k + 1 < MAXV; ++k) {
        for (int v = 1; v < u + 1; ++v) {
            if (parent[k][v] < 0)
                parent[k + 1][v] = -1;
            else {
                parent[k + 1][v] = parent[k][parent[k][v]];
                int t = parent[k][v];
                dpMax[k + 1][v] = max(dpMax[k][v], dpMax[k][t]);
                dpMin[k + 1][v] = min(dpMin[k][v], dpMin[k][t]);
                dpUp[k + 1][v] = max(max(dpUp[k][v], dpUp[k][t]), dpMax[k][t] - dpMin[k][v]);
                dpDown[k + 1][v] = max(max(dpDown[k][v], dpDown[k][t]), dpMax[k][v] - dpMin[k][t]);
            }
        }
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
        init(n);
        LCA(1, -1);
        for (int i = 1; i <= q; ++i) {
            printf("%d\n", (res[i] < 0) ? 0 : res[i]);
        }
    }
}