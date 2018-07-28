#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (100 + 5)

int matrix[MAXN][MAXN];
int row, column;

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &row, &column) != EOF) {
        REP(i, row) {
            int max_n = INT_MIN;
            int max_i = 0;
            int sum = 0;
            REP(j, column) {
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] > max_n) {
                    max_n = matrix[i][j];
                    max_i = j;
                }
                sum += matrix[i][j];
            }
            matrix[i][max_i] = sum;
        }
        REP(i, row) {
            int flag = 0;
            REP(j, column) {
                if (flag) printf(" ");
                printf("%d", matrix[i][j]);
                flag = 1;
            }
            printf("\n");
        }
    }
    return 0;
}