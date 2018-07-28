#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (1000 + 5)
char buf[MAXN];
int vis[MAXN];

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", buf) != EOF) {
        memset(vis, 0, sizeof(vis));
        int len = strlen(buf);
        REP(i, len) {
            if (vis[i]) continue;
            int flg = 0;
            for (int j = i + 1; j < len; ++j) {
                if (buf[j] == buf[i]) {
                    if (!flg) printf("%c:%d", buf[i], i);
                    printf(",%c:%d", buf[j], j);
                    vis[j] = 1;
                    flg = 1;
                }
            }
            if (flg) printf("\n");
        }
    }
    return 0;
}