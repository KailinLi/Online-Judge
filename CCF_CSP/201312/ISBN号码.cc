#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 15;
char input[MAXN];

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", input);
    int k = 1, len = strlen(input);
    int sum = 0;
    REP(i, len - 1) {
        if (input[i] == '-') continue;
        sum += (input[i] - '0') * k++;
    }
    sum %= 11;
    if (input[len - 1] == sum + '0' || (sum == 10 && input[len - 1] == 'X')) printf("Right\n");
    else {
        input[len - 1] = (sum == 10) ? 'X' : sum + '0';
        printf("%s\n", input);
    }
    return 0;
}