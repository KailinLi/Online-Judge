#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int n, x, b;
int res = -1;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &b);
    while (--n) {
        scanf("%d", &x);
        res = max(res, abs(b - x));
        b = x;
    }
    printf("%d\n", res);
    return 0;
}