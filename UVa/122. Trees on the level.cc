#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
const int MAXN = 256 + 10;
char buf[MAXN << 1];
char path[MAXN];
int t;
struct Node {
    bool finish;
    int val;
    Node * left;
    Node * right;
    Node(): finish(false), val(0), left(nullptr), right(nullptr) {}
};
Node node[MAXN];
Node *pool[MAXN];
int pos;
void init_pool() {
    REP(i, MAXN) pool[pos++] = node + i;
}
void free_node(Node *p) {
    pool[pos++] = p;
}
Node * new_node() {
    Node *new_n = pool[--pos];
    new_n->finish = false;
    new_n->val = 0;
    new_n->left = new_n->right = nullptr;
    return new_n;
}
Node *root;
bool add_node() {
    Node *cur = root;
    for (int i = 0; path[i]; ++i) {
        if (path[i] == 'L') {
            if (!cur->left) cur->left = new_node();
            cur = cur->left;
        }
        else if (path[i] == 'R') {
            if (!cur->right) cur->right = new_node();
            cur = cur->right;
        }
    }
    if (cur->finish) return false;
    cur->finish = true;
    cur->val = t;
    return true;
}
Node *queue[MAXN];
int head, tail;
void push(Node *n) {
    queue[tail] = n;
    tail = (tail + 1) % MAXN;
}
Node *pop() {
    Node *ret = queue[head];
    head = (head + 1) % MAXN;
    return ret;
}
void delete_tree(Node *rt) {
    if (!rt) return;
    delete_tree(rt->left);
    delete_tree(rt->right);
    free_node(rt);
    return;
}
void print_tree() {
    int res[MAXN];
    int p = 0;
    head = tail = 0;
    push(root);
    while (head != tail) {
        Node *cur = pop();
        if (!cur->finish) {
            printf("not complete\n");
            delete_tree(root);
            return;
        }
        res[p++] = cur->val;
        if (cur->left) push(cur->left);
        if (cur->right) push(cur->right);
    }
    int first = 0;
    REP(i, p) {
        if (first) printf(" ");
        else first = 1;
        printf("%d", res[i]);
    }
    printf("\n");
    delete_tree(root);
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init_pool();
    root = new_node();
    bool flg = true;
    while (scanf("%s", buf) != EOF) {
        if (!strcmp(buf, "()")) {
            if (flg) print_tree();
            root = new_node();
            flg = true;
        }
        else {
            if (!flg) continue;
            sscanf(buf, "(%d,%s", &t, path);
            if (!add_node()) {
                printf("not complete\n");
                flg = false;
            }
        }
    }
    // print_tree();
    return 0;
}