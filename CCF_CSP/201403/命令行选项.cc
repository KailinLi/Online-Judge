#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const char ERR = 'z' + 1;
const int MAXN = 256 + 5;
struct Argv {
    int type;
    int hit;
    char *para;
};
Argv argv[26];
char check_arg(char *s) {
    if (strlen(s) != 2) return ERR;
    if (s[0] != '-') return ERR;
    if (!(s[1] >= 'a' && s[1] <= 'z')) return ERR;
    return s[1];
}
bool check_para(char *s, char a) {
    for (int i = 0; s[i]; ++i) {
        if (!(isdigit(s[i]) || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '-')) return false;
    }
    argv[a - 'a'].para = (char *)malloc(sizeof(char) * strlen(s) + 1);
    strcpy(argv[a - 'a'].para, s);
    argv[a - 'a'].hit = 1;
    return true;
}
char input[MAXN];
int m;
int kase;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%s", input);
    scanf("%d", &m);
    for (int i = strlen(input) - 1; i >= 0; --i) {
        if (input[i] == ':') argv[input[--i] - 'a'].type = 2;
        else argv[input[i] - 'a'].type = 1;
    }
    getchar();
    while (m--) {
        REP(i, 26) {
            if (argv[i].type == 2 && argv[i].para) free(argv[i].para);
            argv[i].para = NULL;
            argv[i].hit = 0;
        }
        fgets(input, MAXN, stdin);
        char *part = strtok(input, " \n");
        part = strtok(NULL, " \n");
        char ret = 'z' + 1;        
        while (part) {
            if (argv[ret - 'a'].type == 2) {
                if (!check_para(part, ret)) break;
                ret = 'z' + 1;
            }
            else {
                ret = check_arg(part);
                if (ret == ERR) break;
                if (!argv[ret - 'a'].type) break;
                argv[ret - 'a'].hit = 1;
            }
            part = strtok(NULL, " \n");
        }
        printf("Case %d:", ++kase);
        REP(i, 26) {
            if (!argv[i].hit) continue;
            printf(" -%c", i + 'a');
            if (argv[i].type == 2) {
                putchar(' ');
                printf("%s", argv[i].para);
            }
        }
        printf("\n");
    }
    return 0;
}