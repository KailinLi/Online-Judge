#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int p[] = {0, 1500, 4500, 9000, 35000, 55000, 80000, INF};
int t[] = {3, 10, 20, 25, 30, 35, 45};
int n;
int res;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    if (n < 3500) {
        printf("%d\n", n);
        return 0;
    }
    n -= 3500;
    int i = 0;
    for (; i < 7; ++i) {
        if (n < (p[i + 1] - p[i]) / 100 * (100 - t[i])) break;
        else {
            res += p[i + 1] - p[i];
            n -= (p[i + 1] - p[i]) / 100 * (100 - t[i]);
        }
    }
    res += n / (100 - t[i]) * 100;
    printf("%d\n", res + 3500);
    return 0;
}