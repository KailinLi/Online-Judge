#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
// using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 10;
char s[MAXN];
int next[MAXN];
int cur, last;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", s + 1) != EOF) {
        cur = last = 0;
        memset(next, 0, sizeof(next));
        for (int i = 1; s[i]; ++i) {
            if (s[i] == '[') {
                cur = 0;
            }
            else if (s[i] == ']') {
                cur = last;
            }
            else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last) last = i;
                cur = i;
            }
        }
        for (int i = next[0]; i; i = next[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}