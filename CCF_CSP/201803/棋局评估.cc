#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int board[3][3];
int blank;
int n;

bool win_judge (int x, int y, int p) {
    int flg = 1;
    REP(i, 3) if (board[x][i] != p) flg = 0;
    if (flg) return true;
    flg = 1;
    REP(j, 3) if (board[j][y] != p) flg = 0;
    if (flg) return true;
    if (x == y) {
        flg = 1;
        REP(i, 3) if (board[i][i] != p) flg = 0;
        if (flg) return true;
    }
    if (x + y == 2) {
        flg = 1;
        REP(i, 3) if (board[i][2 - i] != p) flg = 0;
        if (flg) return true;
    }
    return false;
}
int search (int p) {
    if (!blank) return 0;
    int best_win = -10;
    int best_lost = 10;
    REP(i, 3) REP(j, 3) {
        if (board[i][j]) continue;
        board[i][j] = p;
        --blank;
        if (win_judge(i, j, p)) {
            board[i][j] = 0;
            ++blank;
            return (p == 1) ? max(blank, best_win) : min(-blank, best_lost);
        }
        if (p == 1) best_win = max(best_win, search(2));
        else best_lost = min(best_lost, search(1));
        board[i][j] = 0;
        ++blank;
    }
    return (p == 1) ? best_win : best_lost;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    while (n--) {
        blank = 0;
        REP(i, 3) REP(j, 3) {
            scanf("%d", &board[i][j]);
            if (!board[i][j]) ++blank;
        }
        int flg = 1;
        for (int i = 0; i < 3 && flg; ++i) for (int j = 0; j < 3 && flg; ++j) {
            if (board[i][j] == 2 && win_judge(i, j, 2)) flg = 0;
        }
        if (!flg) printf("%d\n", -blank - 1);
        else printf("%d\n", search(1));
    }
    return 0;
}