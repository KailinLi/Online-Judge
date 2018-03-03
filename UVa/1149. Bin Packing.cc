#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100000 + 5;
int input[MAXN];
int isVisited[MAXN];
int t, n;
int pSize;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	bool flag = false;
	while (t--) {
		scanf("%d", &n);
		scanf("%d", &pSize);
		for (int i = 0; i < n; ++i)
			scanf("%d", input + i);
		sort(input, input + n);
		int begin = 0, end = n - 1;
		int res = 0;
		memset(isVisited, 0, sizeof(isVisited));
		while (begin < end) {
			if (input[end] + input[begin] <= pSize) {
				isVisited[end--] = 1;
				isVisited[begin++] = 1;
				++res;
			}
			else
				--end;
		}
		for (int i = 0; i < n; ++i)
			if (!isVisited[i])
				++res;
		if (flag) printf("\n");
		flag = true;
		printf("%d\n", res);
	}
}