#include <iostream>
#include <cstring>

using namespace std;
struct Relation {
    int father;
    int relation;
    Relation(): father(0), relation(0) {}
};
const int MAXN = 50000 + 5;
Relation unionFind[MAXN];
int n, k;

int setfind(int x) {
    if (unionFind[x].father == x)
        return x;
    int tmpFather = unionFind[x].father;
    unionFind[x].father = setfind(unionFind[x].father);
    unionFind[x].relation = (unionFind[tmpFather].relation + unionFind[x].relation) % 3;
    return unionFind[x].father;
}

void unionSet(int d, int x, int y, int fx, int fy) {
    unionFind[fx].father = fy;
    unionFind[fx].relation = ((3 - unionFind[x].relation) + unionFind[y].relation + d - 1) % 3;
}
int main () {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        unionFind[i].father = i;
    }
    int res = 0;
    int d, x, y;
    while (k--) {
        scanf("%d %d %d", &d, &x, &y);
        if (x > n || y > n) {
            ++res;
            continue;
        }
        if (d == 2 && x == y) {
            ++res;
            continue;
        }
        int fx = setfind(x);
        int fy = setfind(y);
        if (fx == fy) {
            if (d == 1 && unionFind[x].relation != unionFind[y].relation) {
                ++res;
                continue;
            }
            else if (d == 2 && (unionFind[y].relation + 1) % 3 != unionFind[x].relation) {
                ++res;
                continue;
            }
        }
        else {
            unionSet(d, x, y, fx, fy);
        }
    }
    printf("%d\n", res);
}