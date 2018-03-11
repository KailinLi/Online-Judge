#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 25 + 5;
int dp[MAXN][MAXN];
int v[MAXN];
int n, m;
int id;
map<string, int> name;
int getID(const string &s) {
	map<string, int>::iterator f = name.find(s);
	if (f == name.end()) {
		return name[s] = id++;
	}
	else {
		return f->second;
	}
}
char s1[100], s2[100];
int kase;
void dfs(int u) {
	v[u] = 1;
	REP(i, n) {
		if (!v[i] && dp[i][u] && dp[u][i]) {
			for (map<string, int>::iterator t = name.begin(); t != name.end(); ++t) {
				if (t->second == i) {
					printf(", %s", t->first.c_str());
					break;
				}
			}
			dfs(i);
		}
	}
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d %d", &n, &m) == 2 && n) {
		id = 0;
		name.clear();
		memset(dp, 0, sizeof(dp));
		memset(v, 0, sizeof(v));
		REP(i, n)
			dp[i][i] = 1;
		while (m--) {
			scanf("%s %s", s1, s2);
			dp[getID(s1)][getID(s2)] = 1;	// use const string & !!
		}
		REP(k, n)
			REP(i, n)
				REP(j, n)
					dp[i][j] |= dp[i][k] && dp[k][j];
		if (kase) printf("\n");
		printf("Calling circles for data set %d:\n", ++kase);
		REP(i, n) {
			if (!v[i]) {
				for (map<string, int>::iterator t = name.begin(); t != name.end(); ++t) {
					if (t->second == i) {
						printf("%s", t->first.c_str());
						break;
					}
				}
				dfs(i);
				printf("\n");
			}
		}
	}
	return 0;
}