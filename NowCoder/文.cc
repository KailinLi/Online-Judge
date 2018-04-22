#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 10;
char ans[MAXN];
int N, M;
char name[50 + 5];
char res[50 + 5];
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M); getchar();
    scanf("%s", ans); getchar();
    int mark = -1;
    while (M--) {
        scanf("%s", name); getchar();
        int cnt = 0;
        char getC;
        REP(i, N) {
            getC = (char)getchar();
            if (getC == ans[i]) ++cnt;
        }
        if (mark != -1 && mark == cnt && strcmp(name, res) < 0) strcpy(res, name);
        else if (mark < cnt) {
            mark = cnt;
            strcpy(res, name);
        }
    }
    printf("%s\n", res);
    printf("%.2lf", (double)mark / N * 100);
    return 0;
}