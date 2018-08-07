#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int num[MAXN];
int n, sum;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) scanf("%d", num + i);
    for (int i = 1; i < n - 1; ++i)
        if (num[i - 1] < num[i] && num[i + 1] < num[i]
            || num[i - 1] > num[i] && num[i + 1] > num[i])
            ++sum;
    printf("%d\n", sum); 
    return 0;
}