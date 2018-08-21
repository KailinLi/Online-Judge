#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int vis[MAXN];
int cnt;
int n, k;
int cur = 1;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &k);
    cnt = n;
    int i = 0;
    while (cnt != 1) {
        if (!(cur % k) || cur % 10 == k) {
            vis[i] = 1;
            --cnt;
        }
        ++cur;
        do {
            ++i;
            if (i == n) i = 0;
        } while (vis[i]);
    }
    printf("%d\n", i + 1);
    return 0;
}