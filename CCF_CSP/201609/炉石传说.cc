#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 10;
struct Role {
    int h;
    int a;
};
Role role[MAXN];
int p;
int pos[2][8];
int n;
char input[8];
int c_h, c_a, c_p;
int x, y;
int state;

void summon() {
    role[p].h = c_h;
    role[p].a = c_a;
    for (int i = 7; i > c_p; --i) pos[state][i] = pos[state][i - 1];
    pos[state][c_p] = p;
    ++p;
}
void attack() {
    int enemy = state ? 0 : 1;
    role[pos[state][x]].h -= role[pos[enemy][y]].a;
    role[pos[enemy][y]].h -= role[pos[state][x]].a;
    if (role[pos[state][x]].h <= 0) {
        for (int i = x; i < 7; ++i) pos[state][i] = pos[state][i + 1];
        pos[state][7] = 0;
    }
    if (role[pos[enemy][y]].h <= 0) {
        for (int i = y; i < 7; ++i) pos[enemy][i] = pos[enemy][i + 1];
        pos[enemy][7] = 0;
    }
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    role[0].h = role[1].h = 30;
    role[0].a = role[1].a = 0;
    p = 2;
    pos[0][0] = pos[1][0] = 0;
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%s", input);
        if (!strcmp(input, "end")) {
            state = state ? 0 : 1;
        }
        else if (!strcmp(input, "summon")) {
            scanf("%d %d %d", &c_p, &c_a, &c_h);
            getchar();
            summon();
        }
        else {
            scanf("%d %d", &x, &y);
            getchar();
            attack();
        }
        // REP(k, 2) for (int i = 1; i < 8; ++i) printf("%d*", pos[k][i]);
        // printf("\n");
    }
    if (role[pos[0][0]].h <= 0) printf("1\n");
    else if (role[pos[1][0]].h <= 0) printf("-1\n");
    else printf("0\n");
    REP(k, 2) {
        printf("%d\n", role[pos[k][0]].h);
        int cnt = 0;
        for (int i = 1; i < 8; ++i) if (pos[k][i]) ++cnt;
        printf("%d", cnt);
        for (int i = 1; i < 8; ++i) if (pos[k][i]) printf(" %d", role[pos[k][i]].h);
        printf("\n");
    }
    return 0;
}