#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 100000 + 10;
int BIT[MAXN];
struct Edge {
    int to;
    int next;
};
struct Map {
    int begin;
    int end;
};
Edge edge[MAXN * 2];
int head[MAXN];
Map idMap[MAXN];
int apple[MAXN];
int cnt;
int id;
inline void addEdge(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
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
    while (x < MAXN) {
        BIT[x] += delta;
        x += lowbit(x);
    }
}
void DFS(int u, int father) {
    idMap[u].begin = ++id;
    for (int i = head[u]; i != 0; i = edge[i].next) {
        if (edge[i].to == father)
            continue;
        DFS(edge[i].to, u);
    }
    idMap[u].end = id;
}
int n, i, u, v, m;
char c;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    DFS(1, -1);
    for (i = 1; i <= n; ++i) {
        apple[i] = 1;
    }
    for (i = 1; i <= n; ++i) {
        edit(idMap[i].begin, 1);
    }
    scanf("%d", &m);
    while (m--) {
        getchar();
        scanf("%c %d", &c, &u);
        if (c == 'C') {
            if (apple[u]) {
                apple[u] = 0;
                edit(idMap[u].begin, -1);
            }
            else {
                apple[u] = 1;
                edit(idMap[u].begin, 1);
            }
        }
        else {
            printf("%d\n", apple[u] + sum(idMap[u].end) - sum(idMap[u].begin));
        }
    }
}