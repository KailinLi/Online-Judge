#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 50 + 5;
const int MAXM = 2500 + 10;
struct Edge {
    int to;
    int next;
};
Edge edge[MAXM];
int head[MAXN];
int eCnt;
void addEdge(int u, int v) {
    edge[++eCnt].to = v;
    edge[eCnt].next = head[u];
    head[u] = eCnt;
}
int vis[MAXN];
int father[MAXN];
int n, m;
int u, v;
int stack[MAXN];
int sp;
int flag;
void dfs(int u) {
    vis[u] = 1;
    for (int e = head[u]; e != 0 && !flag; e = edge[e].next) {
        int v = edge[e].to;
        if (vis[v] == 1) {
            flag = 1;
            printf("No\n%d", v);
            int pa = u;
            while (pa != v) {
                printf(",%d", pa);
                pa = father[pa];
            }
            printf(",%d\n", v);
            break;
        }
        else if (vis[v] == 0) {
            father[v] = u;
            dfs(v);
        }
    }
    vis[u] = 2;
    stack[sp++] = u;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    for (int u = 1; u <= n; ++u)
        if (!vis[u]) dfs(u);
    if (!flag) {
        printf("Yes\n%d", stack[--sp]);
        while (sp) {
            printf(",%d", stack[--sp]);
        }
        printf("\n");
    }
    return 0;
}