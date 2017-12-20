#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int BIT[MAXN << 1];
inline int lowbit(int x) {
    return x & (-x);
}
inline int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= lowbit(x);
    }
    return res;
}
inline void edit(int x, int delta) {
    while (x < (MAXN << 1)) {
        BIT[x] += delta;
        x += lowbit(x);
    }
}

struct Edge {
    int to;
    int next;
};
Edge edge[MAXN * 2];
int edgeWeight[MAXN];
int head[MAXN];
int cntEdge;
inline void addEdge(int u, int v) {
    edge[++cntEdge].to = v;
    edge[cntEdge].next = head[u];
    head[u] = cntEdge;
}

int id[MAXN * 2], idToPoint[MAXN * 2];
int depth[MAXN * 2];
int cnt;
int in[MAXN], out[MAXN];
void dfs(int u, int d, int father) {
    id[u] = ++cnt;
    idToPoint[cnt] = u;
    depth[cnt] = d;
    for (int i = head[u]; i != 0; i = edge[i].next) {
        if (edge[i].to == father)
            continue;
        int edgeId = (i + 1) >> 1;
        edit(cnt + 1, edgeWeight[edgeId]);
        in[edgeId] = cnt + 1;
        dfs(edge[i].to, d + 1, u);
        idToPoint[++cnt] = u;
        edit(cnt, -edgeWeight[edgeId]);
        out[edgeId] = cnt;
        depth[cnt] = d;
    }
}

int dp[MAXN * 2][20];
int cmp(int x, int y) {
    return depth[x] < depth[y];
}
void ST(int n) {
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    int len = (int)(log(n * 1.0) / log(2.0));
    for (int j = 1; j <= len; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (i + (1 << j) - 1 > n)
                break;
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1], cmp);
        }
    }
}
int RMQ(int x, int y) {
    if (x > y)
        swap(x, y);
    int k = (int)(log(y - x + 1.0) / log(2.0));
    return min(dp[x][k], dp[y + 1 - (1 << k)][k], cmp);
}

int LCA(int u, int v) {
    return idToPoint[RMQ(id[u], id[v])];
}

int n, mother, state, childCall, num, delta, qtimes;
int u, v;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%d %d %d", &n, &qtimes, &mother) == 3) {
        memset(dp, 0, sizeof(dp));
        memset(BIT, 0, sizeof(BIT));
        memset(head, 0, sizeof(head));
        cnt = 0;
        cntEdge = 0;
        for (int i = 1; i <= n - 1; ++i) {
            scanf("%d %d %d", &u, &v, edgeWeight + i);
            addEdge(u, v);
            addEdge(v, u);
        }
        dfs(1, 1, -1);
        ST((n << 1) - 1);
        while(qtimes--) {
            scanf("%d", &state);
            if (state) {
                scanf("%d %d", &num, &delta);
                edit(in[num], delta - edgeWeight[num]);
                edit(out[num], edgeWeight[num] - delta);
                edgeWeight[num] = delta;
            }
            else {
                scanf("%d", &childCall);
                int root = LCA(mother, childCall);
                printf("%d\n", sum(id[mother]) + sum(id[childCall]) - (sum(id[root]) << 1));
                mother = childCall;
            }
        }
    }
}