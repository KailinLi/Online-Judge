#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
double coefficient[MAXN];
int n, k;
double c;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    REP(i, 2) {
        scanf("%d", &n);
        REP(j, n) {
            scanf("%d", &k);
            scanf("%lf", &c);
            coefficient[k] += c;
        }
    }
    n = 0;
    REP(i, MAXN) {
        if (coefficient[i] != 0.0) ++n;
    }
    printf("%d", n);
    for (int i = MAXN - 1; i >= 0; --i) if (coefficient[i]) {
        printf(" %d %.1lf", i, coefficient[i]);
    }
    printf("\n");
    return 0;
}