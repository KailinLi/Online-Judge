#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) != EOF) {
        int pow = n * n;
        while (n) {
            if (n % 10 != pow % 10) {
                printf("No!\n");
                break;
            }
            pow /= 10;
            n /= 10;
        }
        if (!n) printf("Yes!\n");
    }
    return 0;
}