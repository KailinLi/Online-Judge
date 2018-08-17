#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 5;
const int MAXM = 200000 + 5;
struct Edge {
    int u;
    int v;
    int w;
};
Edge edge[MAXM];
int idx[MAXM];
int pa[MAXN];
int rnk[MAXN];
int ufind(int x) {
    if (pa[x] == x) return x;
    return pa[x] = ufind(pa[x]);
}
void uunion(int x, int y) {
    if (x == y) return;
    if (rnk[x] > rnk[y]) pa[y] = x;
    else {
        pa[x] = y;
        if (rnk[x] == rnk[y]) ++rnk[y];
    }
}
int cmp(const void *lhs, const void *rhs) {
    int li = *(int *)lhs;
    int ri = *(int *)rhs;
    return (edge[li].w > edge[ri].w) ? 1 : -1;
}
int n, m;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    REP(i, n) pa[i + 1] = i + 1;
    REP(i, m) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        idx[i] = i;
    }
    qsort(idx, m, sizeof(int), cmp);
    REP(i, m) {
        int px = ufind(edge[idx[i]].u);
        int py = ufind(edge[idx[i]].v);
        uunion(px, py);
        if (ufind(1) == ufind(n)) {
            printf("%d\n", edge[idx[i]].w);
            break;
        }
    }
    return 0;
}