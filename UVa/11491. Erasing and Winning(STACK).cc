#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 100000 + 5;
char input[MAXN];
int stack[MAXN];
int p;
int n, d;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &d) == 2 && n) {
		getchar();
		p = 0;
		int save = n - d;
		scanf("%s", input);
		REP(i, n) {
			while (d > 0 && p != 0 && stack[p - 1] < input[i]) {
				--p;
				--d;
			}
			stack[p++] = input[i];
		}
		REP(i, min(p, save))
			printf("%c", stack[i]);
		printf("\n");
	}
}