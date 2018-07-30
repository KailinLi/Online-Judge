#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10 + 2;
struct Window {
    int x1;
    int y1;
    int x2;
    int y2;
};
Window w[MAXN];
int idx[MAXN];
int n, m;
int x, y;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    REP(i, n) {
        scanf("%d %d", &x, &y);
        w[i].x1 = x;
        w[i].y1 = y;
        scanf("%d %d", &x, &y);
        w[i].x2 = x;
        w[i].y2 = y;
        idx[n - i - 1] = i;
    }
    while (m--) {
        scanf("%d %d", &x, &y);
        int i = 0;
        for (; i < n; ++i) {
            Window &t = w[idx[i]];
            if (t.x1 <= x && x <= t.x2 && t.y1 <= y && y <= t.y2) break;
        }
        if (i == n) printf("IGNORED\n");
        else {
            printf("%d\n", idx[i] + 1);
            int save = idx[i];
            for (int j = i - 1; j >= 0; --j) idx[j + 1] = idx[j];
            idx[0] = save;
        }
    }
    return 0;
}