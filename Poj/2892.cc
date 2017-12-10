#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 50000 + 5;
int BIT[MAXN];
int stack[MAXN];
int tmp[MAXN];
int sp;
int n, m, x;
char input;
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
    while (x <= n) {
        BIT[x] += delta;
        x += lowbit(x);
    }
}
int countLeft(int x) {
    int left = 0, right = x;
    int mid;
    int pos = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (sum(x) - sum(mid) == 0) {
            pos = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return pos;
}
int countRight(int x) {
    int left = x - 1, right = n;
    int mid;
    int pos = 0;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (sum(mid) - sum(x - 1) > 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            pos = mid;
        }
    }
    return pos;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    while (m--) {
        getchar();
        scanf("%c", &input);
        if (input != 'R')
            scanf("%d", &x);
        switch (input) {
            case 'D':
                tmp[x] = 1;
                stack[sp++] = x;
                edit(x, 1);
                break;
            case 'Q':
                if (tmp[x] == 1) {
                    printf("0\n");
                    continue;
                }
                else {
                    printf("%d\n", countRight(x) - countLeft(x));
                }
                break;
            default:
                int pos = stack[--sp];
                tmp[pos] = 0;
                edit(pos, -1);
                break;
        }
    }
}