#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int BIT[MAXN];
inline int lowbit(int x) {
    return x & (-x);
}
inline int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= lowbit(x);
    }
    return res;
}
inline void edit(int x, int delta) {
    while (x < MAXN) {
        BIT[x] += delta;
        x += lowbit(x);
    }
}
struct CowRange {
    int x;
    int y;
    int index;
    int res;
    CowRange(): x(0), y(0), index(0), res(0) {}
    CowRange(int x, int y, int index): x(x), y(y), index(index), res(0) {}
};
bool preHandle(const CowRange& lhs, const CowRange& rhs) {
    return lhs.x < rhs.x || ((lhs.x == rhs.x) && (lhs.y > rhs.y));
}
bool finishHandle(const CowRange& lhs, const CowRange& rhs) {
    return lhs.index < rhs.index;
}

CowRange cows[MAXN];
int n;
int cnt;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) == 1 && n) {
        int x, y;
        memset(BIT, 0, sizeof(BIT));
        cnt = 0;
        while (cnt < n) {
            scanf("%d %d", &x, &y);
            CowRange &r = cows[cnt++];
            r.x = x;
            r.y = y;
            r.index = cnt;
        }
        int pointCnt = 0, saveCnt = 0;
        sort(cows, cows + cnt, preHandle);
        for (int i = 0; i < cnt; ++i) {
            if (i != 0 && cows[i].y == cows[i - 1].y && cows[i].x == cows[i - 1].x){
                cows[i].res = saveCnt;
            }
            else {
                int aeCnt = pointCnt - sum(cows[i].y + 1);
                cows[i].res = aeCnt;
                saveCnt = aeCnt;
            }
            ++pointCnt;
            edit(cows[i].y + 2, 1);
        }
        sort(cows, cows + cnt, finishHandle);
        for (int i = 0; i < cnt - 1; ++i) {
            printf("%d ", cows[i].res);
        }
        printf("%d\n", cows[cnt - 1].res);
    }
}