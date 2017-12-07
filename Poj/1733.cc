#include <iostream>
#include <cstring>
#include <map>
using namespace std;
struct Relation {
    int father;
    int relation;
    Relation(): father(0), relation(0) {}
};
const int MAXN = 10000 + 3;
const int MAXSIZE = 5000 + 3;
Relation set[MAXN];
unsigned x_array[MAXSIZE];
unsigned y_array[MAXSIZE];
int r_array[MAXSIZE];
int p = 0;
map<unsigned, int> hashMap;
int setFind(int x) {
    if (set[x].father == x) return x;
    int tmpFather = set[x].father;
    set[x].father = setFind(set[x].father);
    set[x].relation = set[x].relation ^ set[tmpFather].relation;
    return set[x].father;
}
void setUnion (int r, int x, int y, int rx, int ry) {
    if (rx < ry) {
        set[ry].father = rx;
        set[ry].relation = r ^ set[x].relation ^ set[y].relation;
    }
    else {
        set[rx].father = ry;
        set[rx].relation = r ^ set[x].relation ^ set[y].relation;
    }
}
// void hashFunction(unsigned t) {
//     hashMap[t] = 0;
// }
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n, size;
    scanf("%d", &n);
    scanf("%d", &size);
    unsigned t_x, t_y;
    int x, y, r;
    char str[5];
    for (int i = 0; i < MAXN; ++i) {
        set[i].father = i;
    }
    int res = 0;
    for (int i = 0; i < size; ++i) {
        scanf("%u %u %s", &t_x, &t_y, str);
        hashMap[t_x] = 0;
        hashMap[t_y] = 0;
        if (str[0] == 'e')
            r_array[i] = 0;
        else
            r_array[i] = 1;
        x_array[i] = t_x;
        y_array[i] = t_y;
    }
    for (map<unsigned, int>::iterator i = hashMap.begin(); 
            i != hashMap.end(); ++i) {
        i->second = ++p;
    }
    for (int i = 0; i < size; ++i) {
        x = hashMap[x_array[i]];
        y = hashMap[y_array[i]];
        r = r_array[i];
        --x;
        int rx = setFind(x);
        int ry = setFind(y);
        if (rx != ry) {
            setUnion(r, x, y, rx, ry);
            ++res;
        }
        else {
            if (set[x].relation ^ set[y].relation ^ r)
                break;
            ++res;
        }
    }
    printf("%d\n", res);
}