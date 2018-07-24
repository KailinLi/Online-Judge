#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (100 + 5)
int a[MAXN];
int n;
int cmp(const void* lhs, const void *rhs) {
    return *(int *)lhs - *(int *)rhs;
}
int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        REP(i, n) scanf("%d", a + i);
        qsort(a, n, sizeof(int), cmp);
        REP(i, n)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}