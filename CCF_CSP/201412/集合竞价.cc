#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 5000 + 5;
struct Stock {
    double price;
    int num;
};
struct Record {
    int buy;
    int sell;
    int price;
};
Record records[MAXN];
int pos_record;
double prices[MAXN];
int pos_prices;
Stock buy[MAXN];
int pos_buy;
int buy_del;
Stock sell[MAXN];
int pos_sell;
int sell_del;
char input[8];
double get_price;
int get_num;
bool cmp_less(const Stock &lhs, const Stock &rhs) {
    return lhs.price > rhs.price;
}
bool cmp_great(const Stock &lhs, const Stock &rhs) {
    return lhs.price < rhs.price;
}

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", input) != EOF) {
        if (!strcmp(input, "buy")) {
            scanf("%lf %d", &get_price, &get_num);
            buy[pos_buy].price = get_price;
            buy[pos_buy++].num = get_num;
            prices[pos_prices++] = get_price;
            records[pos_record].buy = pos_buy;
            records[pos_record++].price = pos_prices;
        }
        else if (!strcmp(input, "sell")) {
            scanf("%lf %d", &get_price, &get_num);
            sell[pos_sell].price = get_price;
            sell[pos_sell++].num = get_num;
            prices[pos_prices++] = get_price;
            records[pos_record].sell = pos_sell;
            records[pos_record++].price = pos_prices;
        }
        else {
            scanf("%d", &get_num);
            --get_num;
            if (records[get_num].buy) {
                buy[records[get_num].buy - 1].price = -1.0;
                prices[records[get_num].price - 1] = 20000.0;
                ++buy_del;
            }
            else {
                sell[records[get_num].sell - 1].price = 20000.0;
                prices[records[get_num].price - 1] = 20000.0;
                ++sell_del;
            }
        }
        getchar();
    }

    sort(buy, buy + pos_buy, cmp_less);
    sort(sell, sell + pos_sell, cmp_great);
    sort(prices, prices + pos_prices);
    pos_buy -= buy_del;
    pos_sell -= sell_del;
    pos_prices -= buy_del + sell_del;

    int sum = 0;
    REP(i, pos_buy) {
        sum += buy[i].num;
        buy[i].num = sum;
    }
    sum = 0;
    REP(i, pos_sell) {
        sum += sell[i].num;
        sell[i].num = sum;
    }
    int max_index = 0, max_price = -1;
    int buy_i = pos_buy - 1, sell_i = 0;
    REP(i, pos_prices) {
        while (buy_i >= 0 && buy[buy_i].price < prices[i]) --buy_i;
        while (sell_i < pos_sell && sell[sell_i].price <= prices[i]) ++sell_i;
        int buy_sum = (buy_i != -1) ? buy[buy_i].num : 0;
        int sell_sum = (sell_i) ? sell[sell_i - 1].num : 0;
        if (max_price <= min(buy_sum, sell_sum)) {
            max_price = min(buy_sum, sell_sum);
            max_index = i;
        }
    }
    printf("%.2lf %d\n", prices[max_index], max_price);
    return 0;
}