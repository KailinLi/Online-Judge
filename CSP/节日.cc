#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int days[12] = {
    31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
int beginY, endY;
int monthIn, weekIn, dayIn;
void printDate(int y, int m, int d) {
    printf("%d/", y);
    if (m < 10)
        printf("0%d/", m);
    else
        printf("%d/", m);
    if (d < 10)
        printf("0%d\n", d);
    else
        printf("%d\n", d);
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d %d %d", &monthIn, &weekIn, &dayIn, &beginY, &endY);
    bool findDay = false;
    for (int year = beginY; year <= endY; ++year) {
        int tmpMonth = monthIn;
        int tmpYear = year;
        if (monthIn < 3) {
            tmpMonth += 12;
            --tmpYear;
        }
        int weekBegin = (1 + 1 + 2 * tmpMonth + 3 * (tmpMonth + 1) / 5 + 
                    tmpYear + tmpYear / 4 - tmpYear / 100 + tmpYear / 400) % 7;
        switch (weekIn) {
            case 1:
                if (dayIn < weekBegin || dayIn > 7)
                    continue;
                printDate(year, monthIn, dayIn - weekBegin + 1);
                findDay = true;
                break;
            case 2:case 3:case 4:case 5: {
                int nextWeekday = 7 - weekBegin + 2;
                nextWeekday += (weekIn - 2) * 7;
                if (dayIn < 1 || dayIn > 7)
                    continue;
                int getDay = nextWeekday + dayIn - 1;
                if (monthIn == 2) {
                    int FebruaryDay = (!(year % 4) && (year % 100)) || !(year % 400) ? 29 : 28;
                    // cout << FebruaryDay << endl;
                    // cout << getDay << endl;
                    if (getDay > FebruaryDay)
                        continue;
                }
                else {
                    if (getDay > days[monthIn - 1])
                        continue;
                }
                printDate(year, monthIn, getDay);
                findDay = true;
                break;
            }
            default:
                break;
        }
    }
    if (!findDay)
        printf("none\n");
}