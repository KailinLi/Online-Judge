#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int n;
int max_h[MAXN][MAXN];

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) scanf("%d", &max_h[i][i]);
    REP(i, n) {
        for (int j = i + 1; j < n; ++j) {
            max_h[i][j] = min(max_h[i][j - 1], max_h[j][j]);
        }
    }
    int s = INT_MIN;
    REP(i, n) {
        for (int j = i; j < n; ++j) {
            s = max(s, max_h[i][j] * (j - i + 1));
        }
    }
    printf("%d\n", s);
    return 0;
}