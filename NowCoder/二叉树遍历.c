#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
#define MAXN (26 + 3)

typedef struct node {
    char val;
    struct node *l;
    struct node *r;
} Node;

char preorder[MAXN];
char inorder[MAXN];
int pre_pos;
Node *make_tree(int in_begin, int in_end) {
    if (in_begin >= in_end) return NULL;
    int i = in_begin;
    for (; i < in_end; ++i) {
        if (preorder[pre_pos] == inorder[i]) break;
    }
    ++pre_pos;
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = inorder[i];
    node->l = make_tree(in_begin, i);
    node->r = make_tree(i + 1, in_end);
    return node;
}
void print_tree(Node *node) {
    if (!node) return;
    print_tree(node->l);
    print_tree(node->r);
    printf("%c", node->val);
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", preorder) != EOF) {
        scanf("%s", inorder);
        pre_pos = 0;
        Node *tree = make_tree(0, strlen(preorder));
        print_tree(tree);
        printf("\n");
    }
    return 0;
}