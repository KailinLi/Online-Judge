#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
struct Record {
    int t;
    int kid;
    bool operator< (const Record &rhs) const {
        return t < rhs.t || (t == rhs.t && kid < rhs.kid);
    }
};
Record borrow[MAXN];
int b_pos;
Record render[MAXN];
int r_pos;
int n, k;
int id, btime, len;
int idx[MAXN];

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &k);
    REP(i, n) idx[i] = i + 1;
    while (k--) {
        scanf("%d %d %d", &id, &btime, &len);
        borrow[b_pos].kid = id;
        borrow[b_pos++].t = btime;
        render[r_pos].kid = id;
        render[r_pos++].t = btime + len;
    }
    borrow[b_pos].t = render[r_pos].t = INF;
    sort(borrow, borrow + b_pos);
    sort(render, render + r_pos);
    int i = 0, j = 0;
    while (true) {
        while (borrow[i].t != INF) {
            REP(f, n) {
                if (idx[f] == borrow[i].kid) {
                    idx[f] = 0;
                    break;
                }
            }
            ++i;
            if (borrow[i].t >= render[j].t) break;
        }
        
        while (render[j].t != INF) {
            REP(f, n) {
                if (!idx[f]) {
                    idx[f] = render[j].kid;
                    break;
                }
            }
            ++j;
            if (render[j].t > borrow[i].t) break;
        }
        if (borrow[i].t == INF && render[j].t == INF) break;
    }
    int first = 1;
    REP(i, n) {
        if (first) first = 0;
        else printf(" ");
        printf("%d", idx[i]);
    }
    printf("\n");
    return 0;
}