#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cctype>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
struct Entry {
    int min[60];
    int hour[24];
    int mday[32];
    int mon[12];
    int wday[7];
    char command[100];
};
Entry entry[20 + 5];
int pos;
int n;
char input[100 + 5];
char month[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", 
                    "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char wday[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fir", "Sat"};

struct Res {
    long long t;
    int idx;
    bool operator< (const Res &rhs) const {
        return t < rhs.t || (t == rhs.t && idx < rhs.idx);
    }
};
Res res[10000 + 5];
int res_pos;


void read_num(int *array, int size) {
    scanf("%s", input);
    if (input[0] == '*') {
        REP(i, size) array[i] = 1;
        return;
    }
    char *c = strtok(input, ",");
    while (c) {
        if (strchr(c, '-')) {
            int b, e;
            sscanf(c, "%d-%d", &b, &e);
            for (int i = b; i <= e; ++i) array[i] = 1;
        }
        else {
            int num;
            sscanf(c, "%d", &num);
            array[num] = 1;
        }
        c = strtok(NULL, ",");
    }
}
int get_idx(char *c, char (*table)[4], int size) {
    if (!isdigit(*c)) {
        REP(i, size) if (!strncmp(c, table[i], 3)) {
            return i;
        }
        return -1;
    }
    else {
        int num;
        sscanf(c, "%d", &num);
        return (table == month) ? num - 1 : num;
    }
}
void read_mark(int *array, char (*table)[4], int size) {
    scanf("%s", input);
    if (input[0] == '*') {
        REP(i, size) array[i] = 1;
        return;
    }
    char *c = strtok(input, ",");
    while (c) {
        char *f = strchr(c, '-');
        if (f) {
            int b, e;
            b = get_idx(c, table, size);
            ++f;
            e = get_idx(f, table, size);
            for (int i = b; i <= e; ++i) array[i] = 1;
        }
        else {
            array[get_idx(c, table, size)] = 1;
        }
        c = strtok(NULL, ",");
    }
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    struct tm t = {}, btime = {}, etime = {};
    scanf("%d %4d%2d%2d%2d%2d %4d%2d%2d%2d%2d", &n, 
                &btime.tm_year, &btime.tm_mon, &btime.tm_mday, &btime.tm_hour, &btime.tm_min,
                &etime.tm_year, &etime.tm_mon, &etime.tm_mday, &etime.tm_hour, &etime.tm_min);
    btime.tm_year -= 1900 - 400;
    etime.tm_year -= 1900 - 400;
    btime.tm_mon -= 1;
    etime.tm_mon -= 1;
    mktime(&btime);
    mktime(&etime);
    getchar();
    while (n--) {
        read_num(entry[pos].min, 60);
        read_num(entry[pos].hour, 24);
        read_num(entry[pos].mday, 32);
        read_mark(entry[pos].mon, month, 12);
        read_mark(entry[pos].wday, wday, 7);
        // fgets(entry[pos].command, 100 + 5, stdin);
        // if (entry[pos].command[strlen(entry[pos].command) - 1] != '\n')
        //     entry[pos].command[strlen(entry[pos].command)] = '\n';
        scanf("%s", entry[pos].command);
        ++pos;
    }
    REP(k, pos) {
        Entry &cur = entry[k];
        for (int m = 0; m < 60; ++m) {
            if (!cur.min[m]) continue;
            for (int h = 0; h < 24; ++h) {
                if (!cur.hour[h]) continue;
                for (int d = 1; d <= 31; ++d) {
                    if (!cur.mday[d]) continue;
                    for (int mon = 0; mon < 12; ++mon) {
                        if (!cur.mon[mon]) continue;
                        for (int w = 0; w < 7; ++w) {
                            if (!cur.wday[w]) continue;
                            for (int y = btime.tm_year; y <= etime.tm_year; ++y) {
                                t.tm_min = m;
                                t.tm_hour = h;
                                t.tm_mday = d;
                                t.tm_mon = mon;
                                t.tm_year = y;
                                time_t cur_time = mktime(&t);
                                if (t.tm_mon != mon) continue;
                                if (t.tm_wday != w) continue;
                                if (difftime(mktime(&btime), cur_time) > 0.0) continue;
                                if (difftime(mktime(&etime), cur_time) <= 0.0) continue;
                                t.tm_year -= 400;
                                mktime(&t);
                                strftime(input, 100 + 5, "%Y%m%d%H%M", &t);
                                sscanf(input, "%lld", &res[res_pos].t);
                                res[res_pos++].idx = k;
                            }
                        }
                    }
                }
            }
        }
    }
    sort(res, res + res_pos);
    REP(i, res_pos) {
        printf("%lld %s\n", res[i].t, entry[res[i].idx].command);
    }
    return 0;
}