#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
unsigned int ip[MAXN];
int m;

void print(unsigned n) {
    unsigned mask = 0xff000000u;
    int first = 0;
    REP(i, 4) {
        if (first) printf(".");
        else first = 1;
        printf("%u", (n & mask) >> (3 * 8));
        n <<= 8;
    }
    printf("\n");
}
int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (scanf("%d", &m) != EOF) {
        unsigned int ns[4];
        memset(ip, 0, sizeof(ip));
        REP(i, m) {
            scanf("%u.%u.%u.%u", ns, ns + 1, ns + 2, ns + 3);
            REP(j, 4) {
                ip[i] |= ns[j] << ((3 - j) * 8);
            }
        }
        int l, flg = 0;
        for (l = 0; l < 32; ++l) {
            for (int j = 1; j < m; ++j) {
                if ((ip[j - 1] & (1u << (31 - l))) != (ip[j] & (1u << (31 - l)))) {
                    flg = 1;
                    break;
                }
            }
            if (flg) break;
        }
        unsigned int mask = ((unsigned int)-1) << (32 - l);
        unsigned int network = ip[0] & mask;
        print(network);
        print(mask);
    }
    return 0;
}