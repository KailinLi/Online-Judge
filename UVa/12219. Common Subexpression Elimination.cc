#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 50000 + 10;
struct Node {
    char name[5];
    int hash;
    int l;
    int r;
    bool operator< (const Node &rhs) const {
        if (hash != rhs.hash) return hash < rhs.hash;
        else if (l != rhs.l) return l < rhs.l;
        else return r < rhs.r;
    }
};
Node node[MAXN];
int cnt;
char expr[MAXN * 6];
int pos;
int t;
int kase;
map<Node, int> dict;
int done[MAXN];

int parse() {
    int id = cnt++;
    Node &u = node[id];
    u.hash = u.name[0] = 0;
    u.l = u.r = -1;
    sscanf(expr + pos, "%[^(,)]", u.name);
    for (int i = 0; u.name[i]; ++i) {
        u.hash = u.hash * 27 + u.name[i] - 'a' + 1;
        ++pos;
    }
    if (expr[pos] == '(') {
        ++pos;
        u.l = parse();
        ++pos;
        u.r = parse();
        ++pos;
    }
    auto f = dict.find(u);
    if (f == dict.end()) return dict[u] = id;
    else {
        --cnt;
        return f->second;
    }
}
void print(int rt) {
    if (done[rt] == kase) {
        printf("%d", rt + 1);
        return;
    }
    done[rt] = kase;
    printf("%s", node[rt].name);
    if (node[rt].l != -1) {
        printf("(");
        print(node[rt].l);
        printf(",");
        print(node[rt].r);
        printf(")");
    }
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &t);
    for (kase = 1; kase <= t; ++kase) {
        scanf("%s", expr);
        cnt = pos = 0;
        dict.clear();
        print(parse());
        printf("\n");
    }
    return 0;
}