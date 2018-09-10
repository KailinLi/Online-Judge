#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
// #include <map>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
// using namespace std;
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
// map<Node, int> dict;
int done[MAXN];

struct Hash {
    int id;
    Hash *next;
    Hash(): id(-1), next(nullptr) {}
};
Hash hash[MAXN];

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

    u.hash = u.hash * 100 + u.l * 10 + u.r;
    Hash &head = hash[u.hash % MAXN];
    Hash *hp = head.next;
    while (hp) {
        if (!strcmp(node[hp->id].name, u.name) 
            && node[hp->id].l == u.l && node[hp->id].r == u.r) break;
        hp = hp->next;
    }
    if (hp) {
        --cnt;
        return hp->id;
    }
    hp = new Hash();
    hp->next = head.next;
    head.next = hp;
    return hp->id = id;
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
        REP(i, MAXN) {
            Hash &h = hash[i];
            Hash *hp = h.next;
            while (hp) {
                Hash *tmp = hp;
                hp = hp->next;
                delete tmp;
            }
            h.next = nullptr;
        }
        print(parse());
        printf("\n");
    }
    return 0;
}