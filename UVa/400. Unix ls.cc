#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
// #define INF 0x3f3f3f3f
#define MAXN (60 + 5)
#define MAXM (100 + 5)
char name[MAXM][MAXN];
int idx[MAXM];
int n;
int cmp(const void *lhs, const void *rhs) {
    int li = *(int *)lhs;
    int ri = *(int *)rhs;
    return strcmp(name[li], name[ri]);
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (scanf("%d", &n) != EOF) {
        getchar();
        int max_len = -1;
        REP(i, n) {
            scanf("%s", name[i]);
            idx[i] = i;
            int len = strlen(name[i]);
            if (len > max_len) max_len = len;
        }
        qsort(idx, n, sizeof(int), cmp);
        REP(i, 60) printf("-");
        printf("\n");
        int r = 1;
        for (; r < 21; ++r) {
            if (r * max_len + (r - 1) * 2 > 60) break;
        }
        --r;
        for (int i = 0; i < n / r + (n % r != 0); ++i) {
            int first = 1;
            for (int j = 0; j < r; ++j) {
                if (first) first = 0;
                else printf("  ");
                if (i + j * (n / r + (n % r != 0)) >= n) break;
                printf("%-*s", max_len, name[idx[i + j * (n / r + (n % r != 0))]]);
            }
            printf("\n");
        }
    }
    return 0;
}