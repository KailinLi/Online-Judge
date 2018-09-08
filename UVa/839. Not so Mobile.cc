#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
int t, tmp;
bool is_balance(int *w) {
    int wl, wr, dl, dr;
    int flg = true;
    scanf("%d %d %d %d", &wl, &dl, &wr, &dr);
    if (!wl) if (!is_balance(&wl)) flg = false;
    if (!wr) if (!is_balance(&wr)) flg = false;
    *w = wl + wr;
    if (flg && wl * dl != wr * dr) return false;
    return flg;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    int first = 0;
    while (t--) {
        if (first) printf("\n");
        else first = 1;
        if (is_balance(&tmp)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}