#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 5000 + 5;
struct Record {
    int type;
    double price;
    int num;
};
Record record[MAXN];
int pos;
double prices[MAXN];
int del_cnt;
char input[8];
double price;
int num;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", input) != EOF) {
        if (!strcmp(input, "buy")) {
            scanf("%lf %d", &price, &num);
            record[pos].type = 1;
            record[pos].price = price;
            prices[pos] = price;
            record[pos++].num = num;
        }
        else if (!strcmp(input, "sell")) {
            scanf("%lf %d", &price, &num);
            record[pos].type = 2;
            record[pos].price = price;
            prices[pos] = price;
            record[pos++].num = num;
        }
        else {
            scanf("%d", &num);
            record[num - 1].type = 0;
            prices[num - 1] = 20000.0;
            prices[pos++] = 20000.0;
            ++del_cnt;
        }
    }
    sort(prices, prices + pos);
    int max_index;
    ll max_price = -1;
    REP(i, pos - 2 * del_cnt) {
        ll buy_sum = 0, sell_sum = 0;
        REP(k, pos) {
            if (!record[k].type) continue;
            if (record[k].type == 1 && record[k].price >= prices[i]) buy_sum += (ll)record[k].num;
            if (record[k].type == 2 && record[k].price <= prices[i]) sell_sum += (ll)record[k].num;
            if (max_price <= min(buy_sum, sell_sum)) {
                max_price = min(buy_sum, sell_sum);
                max_index = i;
            }
        }
    }
    printf("%.2lf %lld\n", prices[max_index], max_price);
    return 0;
}