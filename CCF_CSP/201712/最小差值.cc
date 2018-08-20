#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
int num[MAXN];
int n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) scanf("%d", num + i);
    sort(num, num + n);
    int res = INF;
    for (int i = 1; i < n; ++i) {
        res = min(res, num[i] - num[i - 1]);
    }
    printf("%d\n", res);
    return 0;
}