#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 20000 + 10;
vector<int> node[MAXN];
int n, m;
int x;
int max_sum;
int height(int v) {
    if (node[v].empty()) return 1;
    int st = 0, nd = 0;
    for (int i = 0; i < node[v].size(); ++i) {
        int ret = height(node[v][i]);
        if (ret > st) {
            nd = st;
            st = ret;
        }
        else if (ret > nd) nd = ret;
    }
    max_sum = max(max_sum, st + nd + 1);
    return st + 1;
}
int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n + m; ++i) {
        scanf("%d", &x);
        node[x - 1].push_back(i);
    }
    height(0);
    printf("%d\n", max_sum - 1);
    return 0;
}