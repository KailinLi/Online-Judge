#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 100 + 5;
char field[MAXN][MAXN];
bool poket[MAXN][MAXN];
int m, n;
void dfs(int row, int column, int id) {
	poket[row][column] = id;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (!i && !j) continue;
			if (row + i < 0 || column + j < 0 ||
				row + i >= m || column + j >= n)
				continue;
			if (poket[row + i][column + j] || field[row + i][column + j] != '@')
				continue;
			dfs(row + i, column + j, id);
		}
	}
}
int main () {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (true) {
		scanf("%d %d", &m, &n);
		if (!m) break;
		for (int i = 0; i < m; ++i) {
			scanf("%s", field[i]);
		}
		memset(poket, 0, sizeof(poket));
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!poket[i][j] && field[i][j] == '@')
					dfs(i, j, ++cnt);
			}
		}
		cout << cnt << endl;
	}
}