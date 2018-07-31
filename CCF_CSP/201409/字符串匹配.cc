#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
char input[MAXN];
char pattern[MAXN];
int flg;
int n;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", pattern);
    scanf("%d", &flg);
    scanf("%d", &n);
    int len = strlen(pattern);
    while (n--) {
        scanf("%s", input);
        for (int i = 0; input[i + len - 1]; ++i) {
            int j = 0;
            for (; j < len; ++j) if ((flg == 1 && input[i + j] != pattern[j]) ||
                                        (flg == 0 && tolower(input[i + j]) != tolower(pattern[j]))) break;
            if (j == len) {
                printf("%s\n", input);
                break;
            }
        }
    }
    return 0;
}