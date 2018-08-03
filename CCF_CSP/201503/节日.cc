#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int m, k, w, y_begin, y_end;
char res[20];
struct tm t;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d %d %d", &m, &k, &w, &y_begin, &y_end);
    w %= 7;
    for (int y = y_begin; y <= y_end; ++y) {
        t.tm_year = y - 1900 + 400;
        t.tm_mon = m - 1;
        t.tm_mday = 1;
        mktime(&t);
        int cnt = 0;
        while (true) {
            int cur_w = t.tm_wday;
            if (cur_w == w) {
                if (++cnt == k) {
                    strftime(res, 20, "%Y", &t);
                    printf("%d", atoi(res) - 400);
                    strftime(res, 20, "/%m/%d", &t);
                    printf("%s\n", res);
                    break;
                }
            }
            ++t.tm_mday;
            mktime(&t);
            if (t.tm_mon != m - 1) {
                printf("none\n");
                break;
            }
        }
    }
    return 0;
}