#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (1000 + 5)
char input[MAXN];

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", input) != EOF) {
        int len = strlen(input);
        int i = 0;
        int flg = 1;
        while (i < len >> 1) {
            if (input[i] != input[len - i - 1]) {
                printf("No!\n");
                flg = 0;
                break;
            }
            ++i;
        }
        if (flg) printf("Yes!\n");
    }
    return 0;
}