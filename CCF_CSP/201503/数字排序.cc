#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int num[MAXN];
int idx[MAXN];
int n;
int x;
int cmp(const void *lhs, const void *rhs) {
    int li = *(int *)lhs;
    int ri = *(int *)rhs;
    return (num[li] > num[ri]) ? -1 : ((num[li] == num[ri] && li < ri) ? -1 : 1);
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, MAXN) {
        if (i < n) {
            scanf("%d", &x);
            ++num[x];
        }
        idx[i] = i;
    }
    qsort(idx, MAXN, sizeof(int), cmp);
    REP(i, n) {
        if (!num[idx[i]]) break;
        printf("%d %d\n", idx[i], num[idx[i]]);
    }
    return 0;
}