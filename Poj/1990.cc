#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 20000 + 5;
struct Cow {
    int v;
    int x;
};
bool cmp(const Cow &lhs, const Cow &rhs) {
    return lhs.v < rhs.v;
}
Cow cow[MAXN];
ull BITCount[MAXN];
ull BITDistance[MAXN];
int n;
inline int lowbit(int x) {
    return x & (-x);
}
inline ull sum(int x, ull *BIT) {
    ull res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= lowbit(x);
    }
    return res;
}
inline void edit(int x, ull *BIT, ull delta) {
    while (x < MAXN) {
        BIT[x] += delta;
        x += lowbit(x);
    }
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &cow[i].v, &cow[i].x);
    }
    sort(cow, cow + n, cmp);
    ull res = 0;
    ull totalDistance = 0;
    for (int i = 0; i < n; ++i) {
        ull leftCount = sum(cow[i].x, BITCount);
        ull leftDistance = sum(cow[i].x, BITDistance);
        res += (ull)cow[i].v * (leftCount * (ull)cow[i].x - leftDistance);
        res += (ull)cow[i].v * (totalDistance - leftDistance - ((ull)i - leftCount) * (ull)cow[i].x);
        totalDistance += (ull)cow[i].x;
        edit(cow[i].x, BITCount, 1);
        edit(cow[i].x, BITDistance, (ull)cow[i].x);
    }
    printf("%llu\n", res);
}