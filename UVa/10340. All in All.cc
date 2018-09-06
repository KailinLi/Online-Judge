#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
// const int INF = 0x3f3f3f3f;
struct C {
    char c;
    C * next;
    C(char _c): c(_c), next(nullptr) {}
    C(): next(nullptr) {}
};
C s1, s2;
C *p1, *p2;
char c;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%c", &c) != EOF) {
        p1 = &s1; p2 = &s2;
        do {
            p1->next = new C(c);
            p1 = p1->next;
        } while (scanf("%c", &c) == 1 && c != ' ');
        while (scanf("%c", &c) != EOF && c != '\n') {
            p2->next = new C(c);
            p2 = p2->next;
        }
        p1 = s1.next; p2 = s2.next;
        while (p1 && p2) {
            if (p1->c == p2->c) {
                p1 = p1->next;
                p2 = p2->next;
            }
            else p2 = p2->next;
        }
        if (!p1) printf("Yes\n");
        else printf("No\n");
        p1 = s1.next; p2 = s2.next;
        while (p1) {
            auto tmp = p1;
            p1 = p1->next;
            delete tmp;
        }
        while (p2) {
            auto tmp = p2;
            p2 = p2->next;
            delete tmp;
        }
    }
    return 0;
}