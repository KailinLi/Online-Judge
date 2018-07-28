#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
typedef struct _node {
    int val;
    struct _node *l;
    struct _node *r;
} Node;
Node *new_node(int v) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = v;
    n->l = n->r = NULL;
    return n;
}
int n;
void preorder(Node *h) {
    if (!h) return;
    printf("%d ", h->val);
    preorder(h->l);
    preorder(h->r);
}
void inorder(Node *h) {
    if (!h) return;
    inorder(h->l);
    printf("%d ", h->val);
    inorder(h->r);
}
void postorder(Node *h) {
    if (!h) return;
    postorder(h->l);
    postorder(h->r);
    printf("%d ", h->val);
    free(h);
}

int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        Node *head = NULL;
        int i;
        while (n--) {
            scanf("%d", &i);
            Node *p = head;
            Node *new_n = new_node(i);
            while (p) {
                if (i > p->val) {
                    if (p->r) p = p->r;
                    else {
                        p->r = new_n;
                        break;
                    }
                }
                else if (i < p->val) {
                    if (p->l) p = p->l;
                    else {
                        p->l = new_n;
                        break;
                    }
                }
                else break;
            }
            if (!p) head = new_n;
        }
        preorder(head); printf("\n");
        inorder(head); printf("\n");
        postorder(head); printf("\n");
    }
    return 0;
}