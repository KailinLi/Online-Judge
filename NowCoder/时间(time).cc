#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
char i_time[8];
void add_time(int &h, int &m) {
    if (++m == 60) {
        if (++h == 24)
            h = 0;
        m = 0;
    }
}
void minus_time(int &h, int &m) {
    if (--m == -1) {
        if (--h == -1)
            h = 23;
        m = 59;
    }
}
bool check(int h, int m) {
    int m1 = m / 10;
    int m2 = m % 10;
    int h1 = h / 10;
    int h2 = h % 10;
    if (m1 == h2 && m2 == h1) return true;
    return false;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", i_time);
    int index = 0;
    while(i_time[index] != ':') ++index;
    i_time[index] = '\0';
    int h, m;
    sscanf(i_time, "%d", &h);
    sscanf(i_time + index + 1, "%d", &m);
    do {
        minus_time(h, m);
    } while (!check(h, m));
    printf("%d:%d\n", h, m);
    sscanf(i_time, "%d", &h);
    sscanf(i_time + index + 1, "%d", &m);
    do {
        add_time(h, m);
    } while (!check(h, m));
    printf("%d:%d\n", h, m);
    return 0;
}