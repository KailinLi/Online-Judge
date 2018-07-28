#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f

void trans(int x) {
    if (!x) return;
    trans(x / 8);
    printf("%d", x % 8);
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) != EOF) {
        trans(n);
        printf("\n");
    }
    return 0;
}