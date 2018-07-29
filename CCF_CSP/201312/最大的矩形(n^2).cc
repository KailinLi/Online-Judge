#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int h[MAXN];
int n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) scanf("%d", h + i);
    int s = -INF;
    REP(i, n) {
        int max_h = h[i];
        for (int j = i; j < n; ++j) {
            max_h = min(max_h, h[j]);
            s = max(s, max_h * (j - i + 1));
        }
    }
    printf("%d\n", s);
    return 0;
}