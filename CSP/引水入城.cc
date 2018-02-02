#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 5010;
typedef long long LL;
LL adjacency[MAXN][MAXN][4];
int queue[MAXN * MAXN];
int visited[MAXN * MAXN];
int head, tail;
bool flag;
void push(int x) {
    queue[tail++] = x;
    if (tail >= MAXN * MAXN)
        tail %= MAXN * MAXN;
}
int pop() {
    int tmp = queue[head++];
    if (head >= MAXN * MAXN)
        head %= MAXN * MAXN;
    return tmp;
}
bool isEmpty() {
    return head == tail;
}
void clean() {
    head = tail = 0;
}
int x, A, B, Q;
int m, n;
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d %d %d %d", &n, &m, &A, &B, &Q, &x);
    for (int i = 0; i < m; ++i) {
        adjacency[0][i + 1][3] = 0x3f3f3f3f3f3f3f3f;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            x = (A * x + B) % Q;
            adjacency[i * m + j + 1][(i + 1) * m + j + 1][3] = (LL)x;
            adjacency[(i + 1) * m + j + 1][i * m + j + 1][0] = 0x3f3f3f3f3f3f3f3f;
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            x = (A * x + B) % Q;
            adjacency[(i + 1) * m + j + 1][(i + 1) * m + j + 2][2] = (LL)x;
            adjacency[(i + 1) * m + j + 2][(i + 1) * m + j + 1][1] = (LL)x;
        }
    }
    for (int i = 0; i < m; ++i) {
        adjacency[i + 1 + (n - 1) * m][m * n + 1][3] = 0x3f3f3f3f3f3f3f3f;
    }
    while (true) {
        clean();
        flag = true;
        memset(visited, 0, sizeof(visited));
        push(0);
        visited[0] = 1;
        while (!isEmpty() && flag) {
            int current = pop();
            for()
        }
    }
}