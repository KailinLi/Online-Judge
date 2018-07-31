#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MAXN = (100 + 5) << 1;
struct Point {
    int x;
    int y;
    int cnt;
};
Point points[MAXN];
bool connect[MAXN][MAXN];
bool vis[MAXN];
int n, m, k, r;
bool check(int lhs, int rhs) {
    ULL x1 = (ULL)points[lhs].x, x2 = (ULL)points[rhs].x;
    ULL y1 = (ULL)points[lhs].y, y2 = (ULL)points[rhs].y;
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (ULL)r * (ULL)r;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d %d", &n, &m, &k, &r);
    REP(i, n + m) scanf("%d %d", &points[i].x, &points[i].y);
    REP(i, n + m)
        for (int j = i + 1; j < n + m; ++j)
            connect[i][j] = connect[j][i] = check(i, j);
    queue<int> q;
    q.push(0);
    int layer = 0;
    while (!q.empty()) {
        ++layer;
        for (int len = q.size(), i = 0; i < len; ++i) {
            int p = q.front();
            q.pop();
            REP(j, n + m) {
                if (!vis[j] && connect[j][p]) {
                    if (j == 1) {
                        printf("%d\n", layer - 1);
                        return 0;
                    }
                    vis[j] = true;
                    if (j >= n) ++points[j].cnt;
                    if (points[j].cnt > k) continue;
                    q.push(j);
                }
            }
        }
    }
    return 0;
}