#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN 1000 + 5
int a[MAXN];
int b[MAXN];
int a_length;
int b_length;
int res[MAXN];
int res_length;
char input;
int state;

void fuc() {
    int over = 0;
    int i = a_length - 1;
    int j = b_length - 1;
    while (i >= 0 && j >= 0) {
        int sum = a[i] + b[j] + over;
        over = sum / 10;
        res[res_length++] = sum % 10;
        --i;
        --j;
    }
    while (i >= 0) {
        int sum = a[i] + over;
        over = sum / 10;
        res[res_length++] = sum % 10;
        --i;
    }
    while (j >= 0) {
        int sum = b[j] + over;
        over = sum / 10;
        res[res_length++] = sum % 10;
        --j;
    }
    if (over) printf("%d", over);
    for (int i = res_length - 1; i >= 0; --i)
        printf("%d", res[i]);
    printf("\n");
    a_length = b_length = res_length = 0;
    state = 0;
}

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%c", &input) != EOF) {
        if ((input == '\n' || input == ' ') && a_length && b_length)
            fuc();
        else if ((input == '\n' || input == ' ') && a_length && !b_length)
            state = 1;
        else if (state)
            b[b_length++] = input - '0';
        else
            a[a_length++] = input - '0';
    }
    if (a_length && b_length) fuc();
    return 0;
}