#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
char a[MAXN];
int t;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%s", a);
        int res = 0;
        int len = strlen(a);
        for (int i = 1; i < len; ++i) {
            int c = 0, flg = 0;
            while (c < len) {
                if (a[(res + c) % len] != a[(i + c) % len]) {
                    if (a[(res + c) % len] > a[(i + c) % len]) res = i;
                    break;
                }
                ++c;
            }
            if (c == len) res = i;
        }
        REP(i, len) {
            printf("%c", a[(res + i) % len]);
        }
        printf("\n");
    }
    return 0;
}