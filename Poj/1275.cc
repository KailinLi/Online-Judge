#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 1000 + 10;
const int MAXM = 2000 + 10;
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
int visitedCnt[MAXN];
int qTime;
int m;
int u, v, w;
bool spfa(int s) {
    for (int i = 1; i <= 24; ++i) {
        d[i] = INF;
        inQueue[i] = false;
    }
    d[s] = 0;
    visitedCnt[s] = 1;
    inQueue[s] = true;
    push(s);
    while (!empty()) {
        int current = pop();
        inQueue[current] = false;
        for (int i = head[current]; i != 0; i = edge[i].next) {
            if (d[current] + edge[i].w < d[edge[i].to]) {
                d[edge[i].to] = d[current] + edge[i].w;
                if (!inQueue[edge[i].to]) {
                    if (visitedCnt[edge[i].to]++ > 24)
                        return false;
                    inQueue[edge[i].to] = true;
                    push(edge[i].to);
                }
            }
        }
    }
    return true;
}
int R[25];
int b[25];
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &qTime);
    while (qTime--) {
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= 24; ++i) {
            scanf("%d", R + i);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &u);
            ++b[u + 1];
        }
        int res = 0;
        int l = 1, r = m;
        int middle;
        while (l <= r) {
            middle = (l + r) >> 1;
            memset(head, 0, sizeof(head));
            cnt = h = t = 0;
            memset(visitedCnt, 0, sizeof(visitedCnt));
            for (int i = 8; i <= 24; ++i) {
                addEdge(i, i - 8, -R[i]);
            }
            for (int i = 1; i <= 7; ++i) {
                addEdge(i, i + 16, -R[i] + middle);
            }
            for (int i = 1; i <= 24; ++i) {
                addEdge(i, i - 1, 0);
                addEdge(i - 1, i, b[i]);
            }
            addEdge(24, 0, -middle);
            addEdge(0, 24, middle);
            if (spfa(0)) {
                res = middle;
                r = middle - 1;
            }
            else {
                l = middle + 1;
            }
        }
        if (res)
            printf("%d\n", res);
        else
            printf("No Solution\n");
    }
}