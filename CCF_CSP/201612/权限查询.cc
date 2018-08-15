#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
struct Power {
    char pname[35];
    int grade;
};
struct Role {
    char rname[35];
    int npower;
    int powers[10];
    int grades[10];
};
struct User {
    char uname[35];
    int nrole;
    int roles[10];
};
Power power[100];
Role role[100];
User user[100];
char input[50];
int n;
void read_power(char *buf, int *g) {
    scanf("%s", input);
    char *c = strchr(input, ':');
    if (c == NULL) {
        strcpy(buf, input);
        *g = -1;
    }
    else {
        *c = '\0';
        strcpy(buf, input);
        sscanf(c + 1, "%d", g);
    }
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    getchar();
    REP(i, n) {
        read_power(power[i].pname, &power[i].grade);
    }
    scanf("%d", &n);
    getchar();
    REP(i, n) {
        scanf("%s", role[i].rname);
        scanf("%d", &role[i].npower);
        REP(k, role[i].npower) {
            read_power(input, role[i].grades + k);
            int j = 0;
            while (power[j].pname[0]) {
                if (!strcmp(power[j].pname, input)) break;
                ++j;
            }
            role[i].powers[k] = j;
        }
    }
    scanf("%d", &n);
    getchar();
    REP(i, n) {
        scanf("%s", user[i].uname);
        scanf("%d", &user[i].nrole);
        REP(k, user[i].nrole) {
            scanf("%s", input);
            int j = 0;
            while (role[j].rname[0]) {
                if (!strcmp(role[j].rname, input)) break;
                ++j;
            }
            user[i].roles[k] = j;
        }
    }
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%s", input);
        int k = 0;
        while (user[k].uname[0]) {
            if (!strcmp(user[k].uname, input)) break;
            ++k;
        }
        if (!user[k].uname[0]) {
            printf("false\n");
            scanf("%*s");
            continue;
        }
        int g, max_g = -1;
        read_power(input, &g);
        int flg = 0;
        for (int i = 0; i < user[k].nrole; ++i) {
            REP(j, role[user[k].roles[i]].npower) {
                int idx = role[user[k].roles[i]].powers[j];
                if (!strcmp(power[idx].pname, input) && role[user[k].roles[i]].grades[j] >= g) {
                    flg = 1;
                    if (role[user[k].roles[i]].grades[j] != -1 && g == -1) {
                        flg = 2;
                        max_g = max(max_g, role[user[k].roles[i]].grades[j]);
                    }
                }
            }
        }
        if (flg == 1) printf("true\n");
        else if (flg == 2) printf("%d\n", max_g);
        else printf("false\n");
    }
    return 0;
}