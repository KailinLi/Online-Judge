#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) != EOF) {
        int odd = 0, even = 0;
        int fac = 1;
        REP(i, n) {
            fac *= i + 1;
            if (i % 2) even += fac;
            else odd += fac;
        }
        printf("%d %d\n", odd, even);
    }
    return 0;
}