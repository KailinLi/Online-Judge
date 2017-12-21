#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 100000 + 10;
int color[MAXN << 2];
int lazy[MAXN << 2];
inline void pushUp(int root) {
    color[root] = color[root << 1] | color[root << 1 | 1];
}
inline void pushDown(int root) {
    if (!lazy[root])
        return;
    color[root << 1] = color[root];
    color[root << 1 | 1] = color[root];
    lazy[root << 1] = 1;
    lazy[root << 1 | 1] = 1;
    lazy[root] = 0;
}
void buildTree(int l, int r, int root) {
    if (l == r) {
        color[root] = 1;
        return;
    }
    int m = (l + r) >> 1;
    buildTree(l, m, root << 1);
    buildTree(m + 1, r, root << 1 | 1);
    pushUp(root);
}
void updateTree(int L, int R, int delta, int l, int r, int root) {
    if (r < L || l > R)
        return;
    else if (r <= R && l >= L) {
        lazy[root] = 1;
        color[root] = delta;
        return;
    }
    pushDown(root);
    int m = (l + r) >> 1;
    updateTree(L, R, delta, l, m, root << 1);
    updateTree(L, R, delta, m + 1, r, root << 1 | 1);
    pushUp(root);
}
int queryTree(int L, int R, int l, int r, int root) {
    if (r < L || l > R)
        return 0;
    else if (r <= R && l >= L) {
        return color[root];
    }
    pushDown(root);
    int m = (l + r) >> 1;
    return queryTree(L, R, l, m, root << 1) | queryTree(L, R, m + 1, r, root << 1 | 1);
}
int L, T, O;
char input;
int x, y, c;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &L, &T, &O);
    buildTree(1, L, 1);
    while (O--) {
        getchar();
        scanf("%c", &input);
        if (input == 'C') {
            scanf("%d %d %d", &x, &y, &c);
            if (x > y) swap(x, y);
            updateTree(x, y, 1 << (c - 1), 1, L, 1);
        }
        else {
            scanf("%d %d", &x, &y);
            if (x > y) swap(x, y);
            int n = queryTree(x, y, 1, L, 1);
            int res = 0;
            for (int i = 0; n; ++i) {
                res += n & 1;
                n >>= 1;
            }
            printf("%d\n", res);
        }
    }
}