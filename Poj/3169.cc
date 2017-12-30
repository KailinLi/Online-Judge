#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;
const int MAXM = 200000 + 10;
const int INF = 0x3f3f3f3f;
int q[MAXN];
int h, t;
inline void push(int i) {
    q[t++] = i;
    if (t == MAXN)
        t -= MAXN;
}
inline int pop() {
    int tmp = q[h++];
    if (h == MAXN)
        h -= MAXN;
    return tmp;
}
inline bool empty() {
    return h == t;
}
struct Edge {
    int to;
    int w;
    int next;
};
Edge edge[MAXM];
int head[MAXN];
int cnt;
inline void addEdge(int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int inQueue[MAXN];
int d[MAXN];
int n;
int u, v, w;
int ml, md;
int visitCnt[MAXN];
bool spfa(int s) {
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
    }
    d[s] = 0;
    inQueue[s] = true;
    visitCnt[s] = 1;
    push(s);
    while (!empty()) {
        int current = pop();
        inQueue[current] = false;
        for (int i = head[current]; i != 0; i = edge[i].next) {
            if (d[current] + edge[i].w < d[edge[i].to]) {
                d[edge[i].to] = d[current] + edge[i].w;
                if (!inQueue[edge[i].to]) {
                    inQueue[edge[i].to] = true;
                    push(edge[i].to);
                    if (++visitCnt[edge[i].to] > n)
                        return false;
                }
            }
        }
    }
    return true;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d %d", &n, &ml, &md) == 3) {
        memset(head, 0, sizeof(head));
        memset(visitCnt, 0, sizeof(visitCnt));
        cnt = h = t = 0;
        for (int i = 0; i < ml; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
        }
        for (int i = 0; i < md; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(v, u, -w);
        }
        if (spfa(1)) {
            if (d[n] != INF)
                printf("%d\n", d[n]);
            else
                printf("-2\n");
        }
        else
            printf("-1\n");
    }
}