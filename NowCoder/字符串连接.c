#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
char *a;
char *b;
int length_a;
int length_b;
char input;
int state;
void join() {
    a = (char *)realloc(a, length_a + length_b);
    REP(i, length_b) {
        a[i + length_a] = b[i];
    }
    REP(i, length_a + length_b)
        printf("%c", a[i]);
    printf("\n");
    free(a);
    free(b);
    a = b = NULL;
    length_a = length_b = state = 0;
}
int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%c", &input) != EOF) {
        if (input == '\n') join();
        else if (input == ' ') state = 1;
        else {
            if (state) {
                b = (char *)realloc(b, length_b + 1);
                b[length_b++] = input;
            }
            else {
                a = (char *)realloc(a, length_a + 1);
                a[length_a++] = input;
            }
        }
    }
    if (length_a && length_b) join();
    return 0;
}