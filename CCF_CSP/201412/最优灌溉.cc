#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
const int MAXM = 100000 + 5;
int pa[MAXN];
int rnk[MAXN];
int ufind(int x) {
    if (x == pa[x]) return x;
    else return pa[x] = ufind(pa[x]);
}
void uunion(int x, int y) {
    int px = ufind(x);
    int py = ufind(y);
    if (px == py) return;
    if (rnk[px] > rnk[py]) {
        pa[py] = px;
    }
    else {
        pa[px] = py;
        if (rnk[px] == rnk[py]) ++rnk[py];
    }
}
struct Edge {
    int u;
    int v;
    int d;
    bool operator< (const Edge &rhs) {
        return d < rhs.d;
    }
};
Edge edge[MAXM];
int ecnt;
int n, m;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    REP(i, n)
        pa[i] = i;
    REP(i, m)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].d);
    sort(edge, edge + m);
    int sum = 0;
    for (int i = 0; ecnt < n - 1; ++i) {
        int px = ufind(edge[i].u);
        int py = ufind(edge[i].v);
        if (px == py) continue;
        sum += edge[i].d;
        ++ecnt;
        uunion(px, py);
    }
    printf("%d\n", sum);
    return 0;
}