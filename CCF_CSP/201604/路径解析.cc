#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
char input[MAXN];
char cur[MAXN][MAXN];
int cur_pos;
char path[MAXN << 1][MAXN];
int pos;
int P;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &P);
    getchar();
    scanf("%s", input);
    getchar();
    char *s = strtok(input, "/");
    while (s) {
        strcpy(cur[cur_pos++], s);
        s = strtok(NULL, "/");
    }
    while (P--) {
        fgets(input, MAXN, stdin);
        pos = 0;
        if (!strlen(input)) {
            if (!cur_pos) printf("/");
            else REP(i, cur_pos) printf("/%s", cur[i]);
            printf("\n");
        }
        if (input[0] != '/') {
            REP(i, cur_pos) strcpy(path[pos++], cur[i]);
        }
        s = strtok(input, "/\n");
        while (s) {
            if (!strcmp(s, "..")) pos = pos ? pos - 1 : 0;
            else if (strcmp(s, ".")) strcpy(path[pos++], s);
            s = strtok(NULL, "/\n");
        }
        if (!pos) printf("/");
        else REP(i, pos) printf("/%s", path[i]);
        printf("\n");
    }
    return 0;
}