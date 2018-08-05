#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10 + 5;
char num[MAXN];
int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", num);
    int sum = 0;
    for (int i = 0; num[i]; ++i) {
        sum += num[i] - '0';
    }
    printf("%d\n", sum);
    return 0;
}