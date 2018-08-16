#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100 + 5;
char input[MAXN];
int emphasize(int i);
int link(int i);
int emphasize(int i) {
    printf("<em>");
    ++i;
    while (true) {
        if (input[i] == '\0') break;
        while (input[i] != '_' && input[i] != '[')
            printf("%c", input[i++]);
        if (input[i] == '[') i = link(i);
        else break;
    }
    printf("</em>");
    return i + 1;
}
int link(int i) {
    printf("<a href=\"");
    int text_p = i + 1;
    while (input[++i] != '(');
    ++i;
    while (true) {
        if (input[i] == '\0') break;
        while (input[i] != ')' && input[i] != '_')
            printf("%c", input[i++]);
        if (input[i] == '_') i = emphasize(i);
        else break;
    }
    int ret = i + 1;
    printf("\">");
    i = text_p;
    while (true) {
        if (input[i] == '\0') break;
        while (input[i] != ']' && input[i] != '_')
            printf("%c", input[i++]);
        if (input[i] == '_') i = emphasize(i);
        else break;
    }
    printf("</a>");
    return ret;
}
void sentance(int i) {
    while (input[i] != '\0' && input[i] != '\n') {
        if (input[i] == '_') i = emphasize(i);
        else if (input[i] == '[') i = link(i);
        else printf("%c", input[i++]);
    }
}
void head() {
    int cnt = 0, i = 0;
    while (input[i++] == '#') ++cnt;
    while (input[i] == ' ') ++i;
    printf("<h%d>", cnt);
    sentance(i);
    printf("</h%d>\n", cnt);
}
void list() {
    printf("<ul>\n");
    do {
        if (input[0] != '*') break;
        int i = 0;
        while (input[++i] == ' ');
        printf("<li>");
        sentance(i);
        printf("</li>\n");
    } while (fgets(input, MAXN, stdin));
    printf("</ul>\n");
}
void paragraph() {
    printf("<p>");
    int flg = 0;
    do {
        if (input[0] == '\n' || input[0] == '\0') break;
        if (flg) printf("\n");
        sentance(0);
        flg = 1;
    } while (fgets(input, MAXN, stdin));
    printf("</p>\n");
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (fgets(input, MAXN, stdin)) {
        if (input[0] == '#') head();
        else if (input[0] == '*') list();
        else if (input[0] != '\n' && input[0] != '\0') paragraph();
    }
    return 0;
}