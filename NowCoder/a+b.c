#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (15)

char input[MAXN];

int get_num() {
    int a = 0;
    int flg = 0;
    char *pch = strtok(input, ",");
    while (pch) {
        a *= 1000;
        a += atoi(pch);
        if (a < 0) {
            a = -a;
            flg = 1;
        }
        pch = strtok(NULL, ",");
    }
    return (flg) ? -a : a;
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", input) != EOF) {
        int a = get_num();
        scanf("%s", input);
        int b = get_num();
        printf("%d\n", a + b);
    }
    return 0;
}