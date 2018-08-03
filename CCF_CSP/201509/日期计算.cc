#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
int y, d;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    struct tm t = {};
    scanf("%d %d", &y, &d);
    t.tm_year = y - 1900 + 400;
    t.tm_mon = 0;
    t.tm_mday = d;
    mktime(&t);
    printf("%d\n%d\n", t.tm_mon + 1, t.tm_mday);
    return 0;
}