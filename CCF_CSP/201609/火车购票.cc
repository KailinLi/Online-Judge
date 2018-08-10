#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int chair[20][6];
int n, x;
int flg;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    while (n--) {
        flg = 0;
        scanf("%d", &x);
        REP(i, 20) if (5 - chair[i][0] >= x) {
                REP(k, x) {
                    chair[i][chair[i][0] + k + 1] = 1;
                    if (flg) printf(" ");
                    printf("%d", i * 5 + chair[i][0] + k + 1);
                    flg = 1;
                }
                chair[i][0] += x;
                x = 0;
                break;
        }
        if (x) REP(i, 20) {
                while (x && chair[i][0] < 5) {
                    if (flg) printf(" ");
                    printf("%d", i * 5 + chair[i][0] + 1);
                    flg = 1;
                    chair[i][chair[i][0] + 1] = 1;
                    --x;
                    ++chair[i][0];
                }
        }
        printf("\n");
    }
    return 0;
}