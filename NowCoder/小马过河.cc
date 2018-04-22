#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
int n;
double px, py, ux, uy, vx, vy;

int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf %lf %lf %lf %lf", &px, &py, &ux, &uy, &vx, &vy);
        double k = (vy - uy) / (vx - ux);
        double b1 = (uy * vx - ux * vy) / (vx - ux);
        double b2 = py + (1 / k) * px;
        double x = (b2 - b1) / (k + 1 / k);
        double y = k * x + b1;
        printf("%lf %lf\n", x, y);
    }
    return 0;
}