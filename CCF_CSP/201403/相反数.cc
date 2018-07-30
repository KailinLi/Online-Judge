#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n, i;
    int res = 0;
    set<int> num;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &i);
        set<int>::iterator f = num.find(-i);
        if (f == num.end()) num.insert(i);
        else ++res;
    }
    printf("%d", res);
    return 0;
}