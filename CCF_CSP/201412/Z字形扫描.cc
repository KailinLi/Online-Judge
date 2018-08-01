#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 500 + 5;
int board[MAXN][MAXN];
int n, state;
int x, y;
int xmove[] = {1, -1};
int ymove[] = {-1, 1};

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) REP(j, n) scanf("%d", *(board + i) + j);
    printf("%d", board[x][y]);
    while (x != n - 1 || y != n - 1) {
        if (!state) {
            if (x != n - 1) ++x;
            else ++y;
            printf(" %d", board[y][x]);
            if (x == n - 1 && y == n - 1) break;
            do {
                --x;
                ++y;
                printf(" %d", board[y][x]);
            } while (x > 0 && y < n - 1);
            state = 1;
        }
        else {
            if (y != n - 1) ++y;
            else ++x;
            printf(" %d", board[y][x]);
            if (x == n - 1 && y == n - 1) break;
            do {
                ++x;
                --y;
                printf(" %d", board[y][x]);
            } while (y > 0 && x < n - 1);
            state = 0;
        }
    }
    return 0;
}