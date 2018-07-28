#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (30 + 5)

int id[MAXN];
char name[MAXN][10 + 1];
int age[MAXN];
int idx[MAXN];

int n;

int cmp(const void *lhs, const void *rhs) {
    int li = *(int *)lhs;
    int ri = *(int *)rhs;
    int cmp_age = age[li] - age[ri];
    int cmp_id = id[li] - id[ri];
    int cmp_name = strcmp(name[li], name[ri]);
    return (cmp_age < 0 || (!cmp_age && cmp_id < 0) || 
            (!cmp_age && !cmp_id && cmp_name < 0)) ? -1 : 1;
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        REP(i, n) {
            scanf("%d", id + i);
            scanf("%s", name[i]);
            scanf("%d", age + i);
            idx[i] = i;
        }
        qsort(idx, n, sizeof(int), &cmp);
        REP(i, 3) {
            printf("%d ", id[idx[i]]);
            printf("%s ", name[idx[i]]);
            printf("%d\n", age[idx[i]]);
        }
    }
    return 0;
}