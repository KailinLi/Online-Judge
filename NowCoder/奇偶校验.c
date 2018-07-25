#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
int res[8];
void check(int n) {
    int sum = 0;
    REP(i, 7) {
        res[i] = n % 2;
        if (res[i]) ++sum;
        n >>= 1;
    }
    if (!(sum % 2)) res[7] = 1;
    else res[7] = 0;
    for (int i = 7; i >= 0; --i)
        printf("%d", res[i]);
    printf("\n");
}

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    char input;
    while (scanf("%c", &input) != EOF) {
        if (input == '\n') continue;
        check((int)input);
    }
    return 0;
}