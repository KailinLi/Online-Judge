#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
const int MAXM = 100000 + 10;

struct Edge {
    int to;
    int next;
};
Edge edge[MAXM];
int head[MAXN];
int ecnt;
void addEdge(int u, int v) {
    edge[++ecnt].to = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}

int stack[MAXN];
int pos;
int in_stack[MAXN];
int dfn[MAXN];
int low[MAXN];
int idx;
int res;
int n, m, x, y;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    stack[pos++] = u;
    in_stack[u] = 1;
    for (int e = head[u]; e != 0; e = edge[e].next) {
        int v = edge[e].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v])
            low[u] = min(low[u], dfn[v]);
    }
    int sum = 0;
    if (dfn[u] == low[u]) {
        int v;
        do {
            v = stack[--pos];
            in_stack[v] = 0;
            ++sum;
        } while (v != u);
    }
    res += sum * (sum - 1) / 2;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &x, &y);
        addEdge(x, y);
    }
    REP(i, n) if (!dfn[i + 1]) tarjan(i + 1);
    printf("%d\n", res);
    return 0;
}