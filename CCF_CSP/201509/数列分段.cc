#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000;
int sum, before, x;
int n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    scanf("%d", &before);
    while (--n) {
        scanf("%d", &x);
        if (before != x) ++sum;
        before = x;
    }
    printf("%d\n", sum + 1);
    return 0;
}