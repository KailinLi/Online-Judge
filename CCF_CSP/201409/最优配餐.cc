#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 5;
struct Point {
    int order;
    char is_customer;
    char is_shop;
};
struct Node {
    int x;
    int y;
    LL d;
    Node(int x, int y, LL d): x(x), y(y), d(d) {}
};
Point points[MAXN][MAXN];
int n, m, k;
LL d;
int x, y, order;
int vis[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d %lld", &n, &m, &k, &d);
    queue<Node> q;
    while (m--) {
        scanf("%d %d", &x, &y);
        points[x][y].is_shop = 1;
        vis[x][y] = 1;
        q.push(Node(x, y, 0));
    }
    while (k--) {
        scanf("%d %d %d", &x, &y, &order);
        points[x][y].is_customer = 1;
        points[x][y].order += order;
    }
    while (d--) {
        scanf("%d %d", &x, &y);
        vis[x][y] = 1;
    }
    LL sum = 0;
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        x = node.x;
        y = node.y;
        d = node.d;
        REP(t_i, 4) {
            if (!(x + dx[t_i] <= n && x + dx[t_i] > 0 && y + dy[t_i] <= n && y + dy[t_i] > 0)) continue;
            if (vis[x + dx[t_i]][y + dy[t_i]]) continue;
            if (points[x + dx[t_i]][y + dy[t_i]].is_customer) {
                sum += (d + 1) * (LL)points[x + dx[t_i]][y + dy[t_i]].order;
            }
            vis[x + dx[t_i]][y + dy[t_i]] = 1;
            q.push(Node(x + dx[t_i], y + dy[t_i], d + 1));
        }
    }
    printf("%lld\n", sum);
    return 0;
}