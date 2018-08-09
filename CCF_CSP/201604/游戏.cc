#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
int n, m;
int c;
int x, y, a, b;
int btime[MAXN][MAXN];
int etime[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int queue[2][MAXN * MAXN];
int head, tail;
void enq(int x, int y) {
    queue[0][tail] = x;
    queue[1][tail] = y;
    tail = (tail + 1) % (MAXN * MAXN);
}
int deq() {
    int ret = head;
    head = (head + 1) % (MAXN * MAXN);
    return ret;
}
int q_size() {
    if (tail > head) return tail - head;
    else return tail - head + (MAXN * MAXN);
}
int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &n, &m, &c);
    while (c--) {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        btime[x - 1][y - 1] = a;
        etime[x - 1][y - 1] = b;
    }
    enq(0, 0);
    int res = 0;
    int flg = 1;
    while (q_size() && flg) {
        int cnt = q_size();
        for (int i = 0; i < cnt; ++i) {
            int p = deq();
            x = queue[0][p];
            y = queue[1][p];
            if (x == n - 1 && y == m - 1) {
                flg = 0;
                --res;
                break;
            }
            REP(k, 4) {
                x = queue[0][p] + dx[k];
                y = queue[1][p] + dy[k];
                if (x < 0 || x > n || y < 0 || y > m) continue;
                if (btime[x][y] <= res + 1 && etime[x][y] >= res + 1) continue;
                enq(x, y);
            }
        }
        ++res;
    }
    printf("%d\n", res);
    return 0;
}