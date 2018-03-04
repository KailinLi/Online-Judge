#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100000 + 5;
char input[MAXN];
int isExist[MAXN];
int n, d;
int i;

int segTree[MAXN * 3];
void pushUp(int root) {
	segTree[root] = (input[segTree[root << 1]] >= input[segTree[root << 1 | 1]])
						? segTree[root << 1] : segTree[root << 1 | 1];
}
void buildTree(int l, int r, int root) {
	if (l == r) {
		scanf("%c", input + i);
		segTree[root] = i++;
		return;
	}
	int middle = (l + r) >> 1;
	buildTree(l, middle, root << 1);
	buildTree(middle + 1, r, root << 1 | 1);
	pushUp(root);
}
int query(int L, int R, int l, int r, int root) {
	if (l > R || r < L) {
		return n;
	}
	if (L <= l && r <= R) {
		return segTree[root];
	}
	int middle = (l + r) >> 1;
	int left = query(L, R, l, middle, root << 1);
	int right = query(L, R, middle + 1, r, root << 1 | 1);
	return (input[left] >= input[right]) ? left : right;
}

int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &d) == 2 && n) {
		memset(isExist, 0, sizeof(isExist));
		getchar();
		i = 0;
		buildTree(0, n - 1, 1);
		input[n] = '\0';
		int pos = 0;
		while (d > 0 && pos + d < n) {
			int k = query(pos, pos + d, 0, n - 1, 1);
			for (int i = pos; i < k; ++i) {
				isExist[i] = 1;
				--d;
			}
			pos = k + 1;
		}
		while (d > 0 && pos < n) {
			isExist[pos] = 1;
			--d;
			++pos;
		}
		for (int i = 0; i < n; ++i)
			if (!isExist[i])
				printf("%c", input[i]);
		printf("\n");
	}
}