#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define ROW 4
#define COLUMN 5
int a[ROW][COLUMN];
int res[2][COLUMN];
int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (1) {
        REP(i, ROW) REP(j, COLUMN)
            if (scanf("%d", *(a + i) + j) != 1) return 0;
        REP(k, COLUMN) {
            res[0][k] = res[1][k] = INT_MIN;
            REP(i, ROW) {
                if (res[1][k] < a[i][k] || res[0][k] < a[i][k]) {
                    if (res[0][k] < res[1][k]) res[0][k] = res[1][k];
                    res[1][k] = a[i][k];
                }
            }
        }
        REP(i, 2) {
            REP(j, COLUMN) {
                if (j) printf(" ");
                printf("%d", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}