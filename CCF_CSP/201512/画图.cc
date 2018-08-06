#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
char board[MAXN][MAXN];
int m, n, q;
int t, xa, xb, ya, yb;
char c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y) {
    if (x < 0 || x >= m) return;
    if (y < 0 || y >= n) return;
    if (board[n - 1 - y][x] == '-' || board[n - 1 - y][x] == '|' 
        || board[n - 1 - y][x] == c || board[n - 1 - y][x] == '+') return;
    board[n - 1 - y][x] = c;
    REP(i, 4) dfs(x + dx[i], y + dy[i]);
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &m, &n, &q);
    REP(i, n) REP(j, m) board[i][j] = '.';
    while (q--) {
        scanf("%d", &t);
        if (t) {
            scanf("%d %d %c", &xa, &ya, &c);
            dfs(xa, ya);
        }
        else {
            scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
            if (xa == xb) {
                if (ya > yb) swap(ya, yb);
                REP(i, yb - ya + 1) {
                    if (board[n - 1 - ya - i][xa] == '-' || board[n - 1 - ya - i][xa] == '+') board[n - 1 - ya - i][xa] = '+';
                    else board[n - 1 - ya - i][xa] = '|';
                }
            }
            else {
                if (xa > xb) swap(xa, xb);
                REP(i, xb - xa + 1) {
                    if (board[n - 1 - ya][xa + i] == '|' || board[n - 1 - ya][xa + i] == '+') board[n - 1 - ya][xa + i] = '+';
                    else board[n - 1 - ya][xa + i] = '-';
                }
            }
        }
    }
    REP(i, n) {
        REP(j, m)
            printf("%c", board[i][j]);
        printf("\n");
    }
    return 0;
}