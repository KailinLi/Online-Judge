#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
int n;
int x1, y1, x2, y2;
int board[MAXN][MAXN];

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (y1 > y2) swap(y1, y2);
        for (int i = x1; i < x2; ++i)
            for (int j = y1; j < y2; ++j)
                board[i][j] = 1;
    }
    int sum = 0;
    REP(i, MAXN) REP(j, MAXN) sum += board[i][j];
    printf("%d\n", sum);
    return 0;
}