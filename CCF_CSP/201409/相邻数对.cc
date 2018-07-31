#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int input[MAXN];
int n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) scanf("%d", input + i);
    sort(input, input + n);
    int sum = 0;
    REP(i, n - 1) if (input[i] + 1 == input[i + 1]) ++sum;
    printf("%d\n", sum);
    return 0;
}