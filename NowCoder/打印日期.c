#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
char res[12];

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int y, d;
    while (scanf("%d %d", &y, &d) != EOF) {
        struct tm t = {.tm_year = y - 1900, .tm_mon = 0, .tm_mday = d};
        mktime(&t);
        strftime(res, sizeof(res), "%F", &t);
        printf("%s\n", res);
    }
    return 0;
}