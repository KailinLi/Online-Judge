#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 15;
const int N = 10;
int board[M][N];
int pattern[4][4];
int offset;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    REP(i, M) REP(j, N) scanf("%d", *(board + i) + j);
    REP(i, 4) REP(j, 4) scanf("%d", *(pattern + i) + j);
    scanf("%d", &offset);
    int k = 1;
    int flg = 1;
    for (; k < M + 2 && flg; ++k)
        for (int i = 0; i < 4 && flg; ++i)
            for (int j = 0; j < 4 && flg; ++j)
                if (pattern[i][j] && board[i + k][j + offset - 1])
                    flg = 0;
    REP(i, 4) REP(j, 4) if (pattern[i][j]) k = min(k, 15 - i + 1);
    REP(i, 4) REP(j, 4) if (pattern[i][j]) board[i + k - 2][j + offset - 1] = 1;
    REP(i, M) {
        int flg = 0;
        REP(j, N) {
            if (flg) printf(" ");
            printf("%d", board[i][j]);
            flg = 1;
        }
        printf("\n");
    }
    return 0;
}