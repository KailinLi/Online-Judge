#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100;

unsigned long long gcd(unsigned long long m, unsigned long long n) {
    if (!n) return m;
    return gcd(n, m % n);
}

int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    unsigned long long m, n;
    scanf("%lld %lld", &m, &n);
    if (n > m) swap(m, n);
    printf("%lld\n", m / gcd(m, n) * n);
    return 0;
}