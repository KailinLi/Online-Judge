#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 30 + 10;
int region[MAXN * MAXN];
int m, n;
double w;
int kase;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (scanf("%d %d", &m, &n) == 2 && m && n) {
        REP(i, m) REP(j, n) scanf("%d", region + i * n + j);
        scanf("%lf", &w);
        sort(region, region + m * n);
        w /= 100.0;
        int i = 1;
        double h = 0.0;
        for (; i < m * n && w > 0; ++i) {
            if (w > (region[i] - region[i - 1]) * i) {
                w -= (region[i] - region[i - 1]) * i;
            }
            else {
                h = w / i + region[i - 1];
                w = 0;
            }
        }
        --i;
        if (w > 0) {
            h = region[m * n - 1] + w / (m * n);
            i = m * n;
        }
        printf("Region %d\nWater level is %.2lf meters.\n%.2lf percent of the region is under water.\n\n", ++kase, h, (double)i / (m * n) * 100);
    }
    return 0;
}