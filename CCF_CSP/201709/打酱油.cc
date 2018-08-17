#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int res, n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    while (n >= 50) {
        n -= 50;
        res += 7;
    }
    while (n >= 30) {
        n -= 30;
        res += 4;
    }
    while (n >= 10) {
        n -= 10;
        ++res;
    }
    printf("%d\n", res);
    return 0;
}