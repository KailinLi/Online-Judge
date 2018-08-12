#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
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
    int p = n / 2;
    int l = p, r = p;
    while (l >= 0 && num[l] == num[p]) {
        --l;
    }
    while (r < n && num[r] == num[p]) {
        ++r;
    }
    if (l + 1 == n - r) printf("%d\n", num[p]);
    else printf("-1");
    return 0;
}