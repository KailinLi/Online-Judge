#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 10;
struct State {
    int x;
    int y;
    int t;
    State(int _x, int _y, int _t): x(_x), y(_y), t(_t) {}
};
int danger[2][MAXN * MAXN];
int m, n, t;
int r, c, a, b;
int delta[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
int vis[MAXN][MAXN];

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &n, &m, &t);
    while (t--) {
        scanf("%d %d %d %d", &r, &c, &a, &b);
        danger[0][r * m + c] = a;
        danger[1][r * m + c] = b;
    }
    queue<State> q;
    q.push(State(1, 1, 1));
    vis[1][1] = 1;
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.x == n && cur.y == m) {
            printf("%d\n", cur.t - 1);
            return 0;
        }
        REP(i, 4) {
            int n_x = cur.x + delta[i][0];
            int n_y = cur.y + delta[i][1];
            if (n_x > n || n_y > m || n_x <= 0 || n_y <= 0) continue;
            if (cur.t >= danger[0][n_x * m + n_y] && cur.t <= danger[1][n_x * m + n_y]) continue;
            if (vis[n_x][n_y] == cur.t + 1) continue;
            vis[n_x][n_y] = cur.t + 1;
            q.push(State(n_x, n_y, cur.t + 1));
        }
    }
    return 0;
}