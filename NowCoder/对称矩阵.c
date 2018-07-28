#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (100 + 5)
int matrix[MAXN][MAXN];
int n;

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        REP(i, n) REP(j, n) scanf("%d", *(matrix + i) + j);
        int flg = 1;
        REP(i, n) {
            for (int j = i + 1; j < n; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    printf("No!\n");
                    flg = 0;
                    i += MAXN;  // break loop
                    break;
                }
            }
        }
        if (flg) printf("Yes!\n");
    }
    return 0;
}