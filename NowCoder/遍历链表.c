#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define INF 0x3f3f3f3f
int n;
typedef struct link {
    int val;
    struct link *next;
} Link;
Link head;
int i;
int main (void) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        head.next = NULL;
        Link *p;
        while (n--) {
            scanf("%d", &i);
            p = &head;
            while (p->next && p->next->val < i) p = p->next;
            Link *save = p->next;
            p->next = (Link *)malloc(sizeof(Link));
            p->next->val = i;
            p->next->next = save;
        }
        p = &head;
        int flag = 0;
        while (p->next) {
            if (flag) printf(" ");
            printf("%d", p->next->val);
            Link *del = p;
            p = p->next;
            if (flag) free(del);
            flag = 1;
        }
        printf("\n");
    }
    return 0;
}