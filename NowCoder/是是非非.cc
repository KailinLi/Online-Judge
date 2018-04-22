#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 10;
int a[MAXN];
int n, q;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &q);
    int xorNum = 0;
    REP(i, n) {
        scanf("%d", a + i);
        xorNum ^= a[i];
    }
    int x, y;
    while (q--) {
        scanf("%d %d", &x, &y);
        xorNum ^= a[x - 1];
        xorNum ^= y;
        a[x - 1] = y;
        if (xorNum) printf("Kan\n");
        else printf("Li\n");
    }
    return 0;
}