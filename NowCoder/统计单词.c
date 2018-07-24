#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
char input;
int state;
int sum;

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%c", &input) != EOF) {
        if (input == ' ' && sum) {
            if (state) {
                printf(" ");
            }
            state = 1;
            printf("%d", sum);
            sum = 0;
        }
        else if (input == '.') {
            if (sum) {
                if (state) printf(" ");
                printf("%d", sum);
                sum = 0;
            }
            if (state) printf("\n");
            state = 0;
        }
        else if (input != '\n')
            ++sum;
    }
    return 0;
}