#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int idx[MAXN];
int n, m;
int k, q;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    REP(i, n) idx[i] = i + 1;
    while (m--) {
        scanf("%d %d", &k, &q);
        int i = 0;
        while (idx[i] != k) {
            ++i;
        }
        int std = idx[i];
        if (q > 0) {
            while (q--) {
                idx[i] = idx[i + 1];
                ++i;
            }
            idx[i] = std;
        }
        else if (q < 0) {
            while (q++) {
                idx[i] = idx[i - 1];
                --i;
            }
            idx[i] = std;
        }
    }
    m = 0;
    REP(i, n) {
        if (m) printf(" ");
        printf("%d", idx[i]);
        m = 1;
    }
    printf("\n");
    return 0;
}