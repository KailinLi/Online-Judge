#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXM = 2000 + 5;
const int MAXN = 500 + 5;

int father[MAXN];
int relation[MAXN];
int x_array[MAXM];
int y_array[MAXM];
int r_array[MAXM];
int n, m;
int x, y, r;
int setFind(int x) {
    if (father[x] == x) return x;
    int tmpFather = father[x];
    father[x] = setFind(father[x]);
    relation[x] = (relation[x] + relation[tmpFather]) % 3;
    return father[x];
}
void setUnion(int r, int x, int y, int rx, int ry) {
    // int rx = setFind(x);
    // int ry = setFind(y);
    father[ry] = rx;
    relation[ry] = (relation[x] + (3 - relation[y]) + r) % 3;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d %d", &n, &m) == 2) {
        memset(x_array, 0, sizeof(x_array));
        memset(y_array, 0, sizeof(y_array));
        memset(r_array, 0, sizeof(r_array));
        char rTmp;
        for (int i = 0; i < m; ++i) {
            scanf("%d%c%d", x_array + i, &rTmp, y_array + i);
            if (rTmp == '<')
                r_array[i] = 1;
            else if (rTmp == '>') {
                r_array[i] = 2;
            }
            else
                r_array[i] = 0;
        }
        int judgeCnt = 0;
        int judge = 0;
        int line = -1;
        for (int current = 0; current < n; ++current) {
            for (int i = 0; i < n; ++i) {
                father[i] = i;
            }
            memset(relation, 0, sizeof(relation));
            bool flag = true;
            for (int i = 0; i < m; ++i) {
                x = x_array[i];
                y = y_array[i];
                r = r_array[i];
                if (x == current || y == current)
                    continue;
                int rx = setFind(x);
                int ry = setFind(y);
                if (rx == ry) {
                    if ((relation[y] + (3 - relation[x])) % 3 != r) {
                        // cout << x << " " << y << " " << r << endl;
                        line = max(line, i);
                        flag = false;
                        break;
                    }
                }
                else {
                    setUnion(r, x, y, rx, ry);
                }
            }
            if (flag) {
                judge = current;
                ++judgeCnt;
            }
        }
        if (!judgeCnt) {
            printf("Impossible\n");
        }
        else if (judgeCnt == 1) {
            printf("Player %d can be determined to be the judge after %d lines\n", judge, line + 1);
        }
        else {
            printf("Can not determine\n");
        }
    }
}