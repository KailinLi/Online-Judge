#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 30 + 5;
char s1[MAXN];
char s2[MAXN];
int t;
int dp[MAXN][MAXN];
int cnt[MAXN][MAXN];
int kase;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    getchar();
    while (t--) {
        fgets(s1 + 1, MAXN, stdin);
        fgets(s2 + 1, MAXN, stdin);
        if (s1[strlen(s1 + 1)] == '\n') s1[strlen(s1 + 1)] = '\0';
        if (s2[strlen(s2 + 1)] == '\n') s2[strlen(s2 + 1)] = '\0';
        for (int i = 0, len = strlen(s1 + 1); i <= len; ++i) {
            dp[i][0] = i;
            cnt[i][0] = 1;
        }
        for (int i = 0, len = strlen(s2 + 1); i <= len; ++i) {
            dp[0][i] = i;
            cnt[0][i] = 1;
        }
        for (int i = 1; s1[i]; ++i)
            for (int j = 1; s2[j]; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    cnt[i][j] = cnt[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
                    if (dp[i][j - 1] < dp[i - 1][j]) cnt[i][j] = cnt[i][j - 1];
                    else if (dp[i][j - 1] > dp[i - 1][j]) cnt[i][j] = cnt[i - 1][j];
                    else cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j];
                }
            }
        printf("Case #%d: %d %d\n", ++kase, dp[strlen(s1 + 1)][strlen(s2 + 1)], cnt[strlen(s1 + 1)][strlen(s2 + 1)]);
    }
    return 0;
}