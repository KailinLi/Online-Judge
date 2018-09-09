#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 10;
const int MAXM = 200000 + 10;
struct Edge {
    int to;
    int c;
    int next;
};
Edge edge[MAXM * 2];
int head[MAXN];
int ecnt;
void add_edge(int u, int v, int c) {
    edge[++ecnt].to = v;
    edge[ecnt].c = c;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}
int n, m;
int u, v, c;
int vis[MAXN];
int dis[MAXN];
struct Queue {
    int queue[MAXN];
    int h, t;
    void push(int u) {
        queue[t] = u;
        t = (t + 1) % MAXN;
    }
    int pop() {
        int ret = queue[h];
        h = (h + 1) % MAXN;
        return ret;
    }
    bool empty() {return h == t;}
    int size() {return t >= h ? t - h : (t - h + MAXN);}
    void clean() {h = t = 0;}
};
Queue q;
struct Stack {
    int stack[MAXN];
    int pos;
    void push(int u) {
        stack[pos++] = u;
    }
    int pop() {
        return stack[--pos];
    }
    bool empty() {return pos == 0;}
    void clean() {pos = 0;}
};
Stack stack;
Stack ans;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) == 2) {
        memset(head, 0, sizeof(head));
        ecnt = 0;
        ans.clean();
        REP(i, m) {
            scanf("%d %d %d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        memset(vis, 0, sizeof(vis));
        q.clean();
        vis[n] = 1;
        dis[n] = 0;
        q.push(n);
        while (!q.empty()) {
            int cur = q.pop();
            if (cur == 1) break;
            for (int e = head[cur]; e; e = edge[e].next) {
                if (vis[edge[e].to]) continue;
                dis[edge[e].to] = dis[cur] + 1;
                vis[edge[e].to] = 1;
                q.push(edge[e].to);
            }
        }

        memset(vis, 0, sizeof(vis));
        q.clean();
        vis[1] = 1;
        q.push(1);
        while (!q.empty()) {
            int len = q.size();
            int min_c = INF;
            stack.clean();
            while (len--) {
                int cur = q.pop();
                if (cur == n) break;
                for (int e = head[cur]; e; e = edge[e].next) {
                    if (vis[edge[e].to]) continue;
                    if (dis[edge[e].to] + 1 != dis[cur]) continue;
                    if (min_c < edge[e].c) continue;
                    else if (min_c == edge[e].c) {
                        stack.push(edge[e].to);
                    }
                    else {
                        min_c = edge[e].c;
                        stack.clean();
                        stack.push(edge[e].to);
                    }
                }
            }
            while (!stack.empty()) {
                int u = stack.pop();
                if (!vis[u]) q.push(u);
                vis[u] = 1;
            }
            if (min_c != INF) ans.push(min_c);
        }
        printf("%d\n", ans.pos);
        int first = 1;
        REP(i, ans.pos) {
            if (first) first = 0;
            else printf(" ");
            printf("%d", ans.stack[i]);
        }
        printf("\n");
    }
    return 0;
}