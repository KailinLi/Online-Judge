#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int DNA[4][MAXN];
int t, m, n;
char c;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    while (t--) {
        int res = 0;
        scanf("%d %d", &m, &n);
        memset(DNA, 0, sizeof(DNA));
        REP(i, m) {
            getchar();
            REP(j, n) {
                scanf("%c", &c);
                switch (c)
                {
                    case 'A':
                        ++DNA[0][j];
                        break;
                    case 'C':
                        ++DNA[1][j];
                        break;
                    case 'G':
                        ++DNA[2][j];
                        break;
                    default:
                        ++DNA[3][j];
                        break;
                }
            }
        }
        REP(i, n) {
            if (DNA[0][i] >= DNA[1][i] && DNA[0][i] >= DNA[2][i] && DNA[0][i] >= DNA[3][i]) {
                printf("A");
                res += m - DNA[0][i];
            }
            else if (DNA[1][i] >= DNA[0][i] && DNA[1][i] >= DNA[2][i] && DNA[1][i] >= DNA[3][i]) {
                printf("C");
                res += m - DNA[1][i];
            }
            else if (DNA[2][i] >= DNA[0][i] && DNA[2][i] >= DNA[1][i] && DNA[2][i] >= DNA[3][i]) {
                printf("G");
                res += m - DNA[2][i];
            }
            else {
                printf("T");
                res += m - DNA[3][i];
            }
        }
        printf("\n%d\n", res);
    }
    return 0;
}