#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
int input[MAXN];
int n, k;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &k);
        ++input[k];
    }
    int max_index = 0, max_num = INT_MIN;
    REP(i, MAXN) {
        if (input[i] > max_num) {
            max_num = input[i];
            max_index = i;
        }
    }
    printf("%d\n", max_index);
    return 0;
}