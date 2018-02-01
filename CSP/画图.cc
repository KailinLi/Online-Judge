#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 110;
char canvas[MAXN][MAXN];
int w, h;
void getPosition(int sx, int sy, int &x, int &y) {
    y = sx;
    x = h - sy - 1;
}
void initCanvas() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            canvas[i][j] = '.';
        }
    }
}
inline bool judgeEdge(int x, int y, char c) {
    return canvas[x][y] != '-' && canvas[x][y] != '|' && canvas[x][y] != '+' && canvas[x][y] != c;
}
void DFSPaint(int x, int y, char c) {
    canvas[x][y] = c;
    if (x > 0 && judgeEdge(x - 1, y, c))
        DFSPaint(x - 1, y, c);
    if (y > 0 && judgeEdge(x, y - 1, c))
        DFSPaint(x, y - 1, c);
    if (y < w - 1 && judgeEdge(x, y + 1, c))
        DFSPaint(x, y + 1, c);
    if (x < h - 1 && judgeEdge(x + 1, y, c))
        DFSPaint(x + 1, y, c);
}
void PaintLine(int x, int y, int x2, int y2) {
    if (y == y2) {
        if (x > x2) {
            swap(x, x2);
        }
        for (int i = x; i <= x2; ++i) {
            if (canvas[i][y] != '-' && canvas[i][y] != '+')
                canvas[i][y] = '|';
            else
                canvas[i][y] = '+';
        }
    }
    else {
        if (y > y2)
            swap(y, y2);
        for (int j = y; j <= y2; ++j) {
            if (canvas[x][j] != '|' && canvas[x][j] != '+')
                canvas[x][j] = '-';
            else
                canvas[x][j] = '+';
        }
    }
}
int op;
int t, in_x, in_y, in_x2, in_y2;
char in_ch;
int x, y, x2, y2;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &w, &h, &op);
    initCanvas();
    while(op--) {
        scanf("%d", &t);
        if (t) {
            scanf("%d %d %c", &in_x, &in_y, &in_ch);
            getPosition(in_x, in_y, x, y);
            DFSPaint(x, y, in_ch);
        }
        else {
            scanf("%d %d %d %d", &in_x, &in_y, &in_x2, &in_y2);
            getPosition(in_x, in_y, x, y);
            getPosition(in_x2, in_y2, x2, y2);
            PaintLine(x, y, x2, y2);
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}