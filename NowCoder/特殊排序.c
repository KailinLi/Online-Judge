#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (1000 + 5)
int a[MAXN];
int n;
int max;
int cmp(const void *lhs, const void *rhs) {
    return *(int *)lhs - *(int *)rhs;
}

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        max = INT_MIN;
        REP(i, n) {
            scanf("%d", a + i);
            if (max < a[i]) {
                max = a[i];
                a[i] = a[0];
                a[0] = max;
            }
        }
        if (n > 1)
            qsort(a + 1, n - 1, sizeof(int), cmp);
        printf("%d\n", a[0]);
        if (n <= 1) printf("-1");
        int flag = 0;
        REP(i, n - 1) {
            if (flag) printf(" ");
            printf("%d", a[i + 1]);
            flag = 1;
        }
        printf("\n");
    }
    return 0;
}