#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f

typedef struct node {
    int val;
    struct node *l;
    struct node *r;
} Node;
int n;
Node *tree = NULL;

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    while (n--) {
        int i;
        scanf("%d", &i);
        Node *pa = NULL;
        Node *rt = tree;
        while (rt) {
            pa = rt;
            if (i > pa->val)
                rt = rt->r;
            else
                rt = rt->l;
        }
        rt = (Node *)malloc(sizeof(Node));
        rt->val = i;
        rt->l = rt->r = NULL;
        if (!pa) {
            printf("-1\n");
            tree = rt;
        }
        else {
            printf("%d\n", pa->val);
            if (i > pa->val) pa->r = rt;
            else pa->l = rt;
        }
    }
    return 0;
}