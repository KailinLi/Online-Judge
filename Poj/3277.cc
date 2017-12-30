#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const ll MAXN = 600000;
map<ll, ll> hashMap;
ll cnt;
ll size;
ll hashArray[MAXN];
struct Question {
    ll u;
    ll v;
    ll h;
};
Question question[MAXN];
ll segTree[MAXN << 2];
bool lazy[MAXN];
inline void pushUp(ll root) {
    segTree[root] = max(segTree[root << 1], segTree[root << 1 | 1]);
}
inline void pushDown(ll root) {
    if (!lazy[root])
        return;
    segTree[root << 1] = max(segTree[root << 1], segTree[root]);
    segTree[root << 1 | 1] = max(segTree[root << 1 | 1], segTree[root]);
    lazy[root << 1] = true;
    lazy[root << 1 | 1] = true;
    lazy[root] = false;
}
void updateTree(ll L, ll R, ll h, ll l, ll r, ll root) {
    if (r < L || l > R)
        return;
    else if (r <= R && l >= L) {
        lazy[root] = 1;
        segTree[root] = max(segTree[root], h);
        return;
    }
    pushDown(root);
    ll m = (l + r) >> 1;
    updateTree(L, R, h, l, m, root << 1);
    updateTree(L, R, h, m + 1, r, root << 1 | 1);
}
ll queryTree(ll L, ll R, ll l, ll r, ll root) {
    pushDown(root);
    if (l == r) {
        return  segTree[root] * (hashArray[l + 1] - hashArray[l]);
    }
    ll m = (l + r) >> 1;
    return queryTree(L, R, l, m, root << 1) + queryTree(L, R, m + 1, r, root << 1 | 1);
}
ll n;
ll u, v, h;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%lld", &n) == 1) {
        cnt = 0;
        size = 0;
        hashMap.clear();
        memset(segTree, 0, sizeof(segTree));
        for (int i = 0; i < MAXN; ++i) {
            lazy[i] = false;
        }
        while (n--) {
            scanf("%lld %lld %lld", &u, &v, &h);
            if (u > v)
                swap(u, v);
            question[++cnt].u = u;
            question[cnt].v = v;
            question[cnt].h = h;
            hashMap[u] = 0;
            hashMap[v] = 0;
        }
        for (map<ll, ll>::iterator i = hashMap.begin(); i != hashMap.end(); ++i) {
            i->second = ++size;
            hashArray[size] = i->first;
        }
        for (int i = 1; i <= cnt; ++i) {
            updateTree(hashMap[question[i].u], hashMap[question[i].v] - 1, question[i].h, 1, size, 1);
        }
        printf("%lld\n", queryTree(1, size, 1, size, 1));
    }
}