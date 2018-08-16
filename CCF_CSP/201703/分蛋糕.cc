#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int a, x;
int n, k;
int res;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &k);
    while (n--) {
        scanf("%d", &a);
        x += a;
        if (x >= k) {
            ++res;
            x = 0;
        }
    }
    printf("%d\n", res + (x != 0));
    return 0;
}