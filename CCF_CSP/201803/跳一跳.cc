#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int res;
int x, b = 1;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &x) == 1 && x) {
        if (x == 1)
            res += b = 1;
        else {
            if (b == 1)
                res += b = 2;
            else
                res += b += 2;
        }
    }
    printf("%d\n", res);
    return 0;
}