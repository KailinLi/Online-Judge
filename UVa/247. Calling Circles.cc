#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 25 + 5;
int dp[MAXN][MAXN];
char name[MAXN][MAXN];
char buf[MAXN];
int pos;
int n, m;
int get_id() {
    int i = 0;
    while (i < pos) {
        if (!strcmp(buf, name[i])) break;
        ++i;
    }
    if (i == pos) {
        strcpy(name[pos], buf);
        return pos++;
    }
    else return i;
}
int vis[MAXN];
void dfs(int u) {
    printf("%s", name[u]);
    REP(i, n) {
        if (dp[u][i] && dp[i][u] && !vis[i]) {
            printf(", ");
            vis[i] = 1;
            dfs(i);
        }
    }
}
int kase;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        pos = 0;
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        REP(i, n) dp[i][i] = 1;
        while (m--) {
            scanf("%s", buf);
            int u = get_id();
            scanf("%s", buf);
            int v = get_id();
            dp[u][v] = 1;
        }
        REP(k, n) REP(i, n) REP(j, n) dp[i][j] |= dp[i][k] && dp[k][j];
        if (kase) printf("\n");
        printf("Calling circles for data set %d:\n", ++kase);
        REP(i, n) if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
            printf("\n");
        }
    }
    return 0;
}