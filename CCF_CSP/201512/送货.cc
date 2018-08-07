#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
const int MAXM = 100000 + 5;
struct Edge {
    int id;
    int to;
    int next;
};
Edge edge[MAXM << 1];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, int id) {
    edge[++ecnt].to = v;
    edge[ecnt].id = id;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}
int vis[MAXM];
int deg[MAXN];
int n, m;
int u, v;
int res[MAXN];
int res_pos;
struct Pos {
    int id;
    int to;
    bool operator< (const Pos &rhs) {
        return this->to < rhs.to;
    }
};
Pos neg[MAXN];
void dfs(int u) {
    int cnt = 0;
    for (int e = head[u]; e != 0; e = edge[e].next) {
        if (vis[edge[e].id]) continue;
        neg[cnt].id = edge[e].id;
        neg[cnt++].to = edge[e].to;
    }
    sort(neg, neg + cnt);
    REP(i, cnt) {
        if (vis[neg[i].id]) continue;
        vis[neg[i].id] = 1;
        dfs(neg[i].to);
    }
    res[res_pos++] = u;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    REP(i, m) {
        scanf("%d %d", &u, &v);
        add_edge(u, v, i);
        add_edge(v, u, i);
        ++deg[u];
        ++deg[v];
    }
    int s = -1, sum = 0;
    REP(i, n) if (deg[n - i] % 2) {
        s = n - i;
        ++sum;
    }
    if (sum != 0 && sum != 2 || sum == 2 && s != 1) {
        printf("-1\n");
        return 0;
    }
    if (s == -1) s = 1;
    dfs(s);
    if (res_pos == m + 1) {
        int flg = 0;
        for (int i = res_pos - 1; i >= 0; --i) {
            if (flg) printf(" ");
            printf("%d", res[i]);
            flg = 1;
        }
        printf("\n");
    }
    else printf("-1\n");
    return 0;
}