#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 26;
struct Matrix {
    int row;
    int col;
};
Matrix matrix[26];
Matrix stack[1024000];
int p;
int n, row, col;
char c;

int main (void) {
    // std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP(i, n) {
        scanf("%*c%c %d %d", &c, &row, &col);
        // cout << row << " " << col << endl;
        matrix[c - 'A'].row = row;
        matrix[c - 'A'].col = col;
    }
    getchar();
    int res = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("%d\n", res);
            res = p = 0;
        }
        else if (c == '(') {
            // stack[p++].col = -INF;
        }
        else if (c == ')') {
            Matrix mtx1 = stack[--p];
            Matrix mtx2 = stack[--p];
            if (mtx2.col != mtx1.row) {
                printf("error\n");
                p = res = 0;
                while ((c = getchar()) != EOF && c != '\n');
            }
            else {
                res += mtx2.row * mtx2.col * mtx1.col;
                stack[p].row = mtx2.row;
                stack[p++].col = mtx1.col;
            }
        }
        else {
            stack[p++] = matrix[c - 'A'];
        }
    }
    if (p) printf("%d\n", res);
    return 0;
}