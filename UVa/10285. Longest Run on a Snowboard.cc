#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
char name[MAXN];
int t, m, n;
int d[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
int get_dp(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    REP(t, 4) {
        int ni = i + d[t][0], nj = j + d[t][1];
        if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
        if (a[ni][nj] < a[i][j]) dp[i][j] = max(dp[i][j], get_dp(ni, nj));
    }
    return dp[i][j] += 1;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%s %d %d", name, &m, &n);
        REP(i, m) REP(j, n) scanf("%d", *(a + i) + j);
        memset(dp, -1, sizeof(dp));
        int max_l = -1;
        REP(i, m) REP(j, n) max_l = max(max_l, get_dp(i, j));
        printf("%s: %d\n", name, max_l + 1);
    }
    return 0;
}