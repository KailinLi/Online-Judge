#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 50000;
struct SegTree {
    int hole;
    int leftHole;
    int rightHole;
    int lazy;
};
SegTree segTree[MAXN << 2];
inline void pushUp(int root, int len) {
    segTree[root].leftHole = segTree[root << 1].leftHole;
    segTree[root].rightHole = segTree[root << 1 | 1].rightHole;
    if (segTree[root].leftHole == len - (len >> 1))
        segTree[root].leftHole += segTree[root << 1 | 1].leftHole;
    if (segTree[root].rightHole == (len >> 1))
        segTree[root].rightHole += segTree[root << 1].rightHole;
    segTree[root].hole = max(segTree[root << 1].rightHole + segTree[root << 1 | 1].leftHole, 
                                max(segTree[root << 1].hole, segTree[root << 1 | 1].hole));
}
inline void pushDown(int root, int len) {
    if (segTree[root].lazy == -1)
        return;
    if (segTree[root].lazy) {
        segTree[root << 1].leftHole = segTree[root << 1].rightHole = segTree[root << 1].hole = len - (len >> 1);
        segTree[root << 1 | 1].leftHole = segTree[root << 1 | 1].rightHole = segTree[root << 1 | 1].hole = len >> 1;
    }
    else {
        segTree[root << 1].leftHole = segTree[root << 1].rightHole = segTree[root << 1].hole = 0;
        segTree[root << 1 | 1].leftHole = segTree[root << 1 | 1].rightHole = segTree[root << 1 | 1].hole = 0;
    }
    segTree[root << 1].lazy = segTree[root << 1 | 1].lazy = segTree[root].lazy;
    segTree[root].lazy = -1;
}
void buildTree(int l, int r, int root) {
    segTree[root].hole = segTree[root].leftHole = segTree[root].rightHole = r - l + 1;
    segTree[root].lazy = -1;
    if (l == r)
        return;
    int middle = (l + r) >> 1;
    buildTree(l, middle, root << 1);
    buildTree(middle + 1, r, root << 1 | 1);
}
void updateTree(int L, int R, int delta, int l, int r, int root) {
    if (r < L || l > R)
        return;
    else if (r <= R && l >= L) {
        segTree[root].hole = segTree[root].leftHole = segTree[root].rightHole = delta ? r - l + 1 : 0;
        segTree[root].lazy = delta;
        return;
    }
    pushDown(root, r - l + 1);
    int middle = (l + r) >> 1;
    updateTree(L, R, delta, l, middle, root << 1);
    updateTree(L, R, delta, middle + 1, r, root << 1 | 1);
    pushUp(root, r - l + 1);
}
int queryTree(int l, int r, int root, int q) {
    if (l == r)
        return l;
    pushDown(root, r - l + 1);
    int middle = (l + r) >> 1;
    if (segTree[root << 1].hole >= q)
        return queryTree(l, middle, root << 1, q);
    else if (segTree[root << 1].rightHole + segTree[root << 1 | 1].leftHole >= q)
        return middle - segTree[root << 1].rightHole + 1;
    else
        return queryTree(middle + 1, r, root << 1 | 1, q);
}
int n, m;
int u, v, op;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) == 2) {
        buildTree(1, n, 1);
        while (m--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &u);
                if (segTree[1].hole < u)
                    printf("0\n");
                else {
                    int pos = queryTree(1, n, 1, u);
                    printf("%d\n", pos);
                    updateTree(pos, pos + u - 1, 0, 1, n, 1);
                }
            }
            else {
                scanf("%d %d", &u, &v);
                updateTree(u, u + v - 1, 1, 1, n, 1);
            }
        }
    }
}