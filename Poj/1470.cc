#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1000 + 10;
int father[MAXN];
int Rank[MAXN];
int visited[MAXN];
int ancestor[MAXN];
int res[MAXN];
vector<int> son[MAXN];
vector<int> q[MAXN];
int n;

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
void LCA(int u) {
    ancestor[u] = u;
    for (vector<int>::iterator v = son[u].begin(); v != son[u].end(); ++v) {
        LCA(*v);
        setUnion(u, *v);
        ancestor[setFind(u)] = u;
    }
    visited[u] = 1;
    for (vector<int>::iterator v = q[u].begin(); v != q[u].end(); ++v) {
        if (visited[*v]) {
            ++res[ancestor[setFind(*v)]];
        }
    }
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) == 1) {
        int u, v;
        int i;
        for (i = 1; i <= n; ++i) {
            father[i] = i;
            son[i].clear();
            q[i].clear();
        }
        memset(Rank, 1, sizeof(Rank));
        memset(visited, 0, sizeof(visited));
        memset(ancestor, 0, sizeof(ancestor));
        memset(res, 0, sizeof(res));
        for (i = 1; i <= n; ++i) {
            int sonCnt;
            scanf("%d:(%d)", &u, &sonCnt);
            while(sonCnt--) {
                scanf("%d", &v);
                ++res[v];
                son[u].push_back(v);
            }
        }
        int qCnt;
        scanf("%d", &qCnt);
        while(qCnt--) {
            scanf(" (%d %d)", &u, &v);
            q[u].push_back(v);
            q[v].push_back(u);
        }
        for (i = 1; i <= n; ++i) {
            if (!res[i])
                break;
        }
        memset(res, 0, sizeof(res));
        LCA(i);
        for (i = 1; i <= n; ++i) {
            if (res[i])
                printf("%d:%d\n", i, res[i]);
        }
    }
}