#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <climits>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
int n, k;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    map<int, int> num;
    REP(i, n) {
        scanf("%d", &k);
        map<int, int>::iterator f = num.find(k);
        if (f != num.end())
            ++f->second;
        else num[k] = 1;
    }
    int max_cnt = INT_MIN, max_index = 0;
    for (map<int, int>::iterator i = num.begin(); i != num.end(); ++i) {
        if (i->second > max_cnt) {
            max_cnt = i->second;
            max_index = i->first;
        }
    }
    printf("%d\n", max_index);
    return 0;
}