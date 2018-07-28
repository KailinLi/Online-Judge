#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (100 + 5)
#define MAXM (1000 + 5)
char num[MAXN][MAXM];
char buf[MAXM];
int idx[MAXN];
int n;
int max_len;
int cmp(const void *lhs, const void *rhs) {
    return strcmp(num[*(int *)lhs] + MAXM - max_len - 1, num[*(int *)rhs] + MAXM - max_len - 1);
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        max_len = INT_MIN;
        REP(i, n) REP(j, MAXM - 1) num[i][j] = '0';
        REP(i, n) {
            scanf("%s", buf);
            int len = strlen(buf);
            max_len = (max_len < len) ? len : max_len;
            for (int j = len - 1; j >= 0; --j)
                num[i][MAXM + j - len - 1] = buf[j];
            idx[i] = i;
        }
        qsort(idx, n, sizeof(int), cmp);
        REP(i, n) {
            int j = 0;
            while (num[idx[i]][j] == '0') ++j;
            for (; j < MAXM - 1; ++j) {
                printf("%c", num[idx[i]][j]);
            }
            printf("\n");
        }
    }
    return 0;
}