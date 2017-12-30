#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 60000 + 10;
const int MAXM = 240000 + 10;
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
bool inQueue[MAXN];
int d[MAXN];
int n;
int u, v, w;
int left, right;
bool spfa(int s) {
    for (int i = ::left; i <= ::right; ++i) {
        d[i] = INF;
        inQueue[i] = false;
    }
    d[s] = 0;
    inQueue[s] = true;
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
                }
            }
        }
    }
    return true;
}
int main (int argc, char * argv[]) {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) == 1) {
        memset(head, 0, sizeof(head));
        cnt = h = t = 0;
        ::left = MAXN;
        ::right = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(v + 1, u, -w);
            ::left = min(::left, u);
            ::right = max(::right, v + 1);
        }
        for (int i = ::left; i <= ::right; ++i) {
            addEdge(i, i - 1, 0);
            addEdge(i - 1, i, 1);
        }
        spfa(::right);
        printf("%d\n", d[::right] - d[::left]);
    }
}