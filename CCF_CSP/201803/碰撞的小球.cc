#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
struct Idx {
    int idx;
    int x;
    bool operator< (const Idx &rhs) const {
        return x < rhs.x;
    }
};
Idx idx[MAXN];
int idx_pos[MAXN];
int num[MAXN];
int pos;
int n, l, t;
int x;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &n, &l, &t);
    int delta = t % (l * 2);
    while (n--) {
        scanf("%d", &x);
        idx[pos].x = x;
        idx[pos].idx = pos;
        x += delta;
        if (x > l) x = 2 * l - x;
        if (x < 0) x = -x;
        num[pos++] = x;
    }
    sort(idx, idx + pos);
    sort(num, num + pos);
    REP(i, pos) idx_pos[idx[i].idx] = i;
    int flg = 0;
    REP(i, pos) {
        if (flg) printf(" ");
        printf("%d", num[idx_pos[i]]);
        flg = 1;
    }
    printf("\n");
    return 0;
}