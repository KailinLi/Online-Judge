#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int h[MAXN];
int stack[MAXN];
int n, pos;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) scanf("%d", h + i);
    int s = -INF;
    REP(i, n + 1) {
        while (pos && h[stack[pos - 1]] >= h[i]) {
            int height = h[stack[--pos]];
            int idx = (pos) ? stack[pos - 1] : -1;
            s = max(s, height * (i - 1 - idx));
        }
        stack[pos++] = i;
    }
    printf("%d\n", s);
    return 0;
}