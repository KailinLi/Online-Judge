#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (1000 + 5)
#define MAXM (100 + 1)
int n;
char name[MAXN][MAXM];
int age[MAXN];
int grade[MAXN];
int a_index[MAXN];
int cmp(const void *lhs, const void *rhs) {
    int li = *(int *)lhs;
    int ri = *(int *)rhs;
    int cmp_grade = grade[li] - grade[ri];
    if (cmp_grade < 0) return cmp_grade;
    int cmp_name = strcmp(name[li], name[ri]);
    if (!cmp_grade && cmp_name < 0) return cmp_name;
    if (!cmp_grade && !cmp_name && age[li] - age[ri] < 0) return -1;
    else return 1;
}
int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        REP(i, n) {
            scanf("%s", name[i]);
            scanf("%d", age + i);
            scanf("%d", grade + i);
            a_index[i] = i;
        }
        qsort(a_index, n, sizeof(int), cmp);
        REP(i, n) {
            printf("%s ", name[a_index[i]]);
            printf("%d ", age[a_index[i]]);
            printf("%d\n", grade[a_index[i]]);
        }
    }
    return 0;
}