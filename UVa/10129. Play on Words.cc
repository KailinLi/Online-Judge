#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000 + 5;
char input[MAXN];
int inDeg[26];
int outDeg[26];
int set[26];
int Rank[26];
int t, n;
int setFind(int x) {
	if (set[x] == x)
		return x;
	return set[x] = setFind(set[x]);
}
void setUnion(int px, int py) {
	if (Rank[px] > Rank[py]) {
		set[py] = px;
		Rank[px] += Rank[py];
	}
	else {
		set[px] = py;
		Rank[py] += Rank[px];
	}
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int part = 26;
		memset(inDeg, 0, sizeof(inDeg));
		memset(outDeg, 0, sizeof(outDeg));
		memset(Rank, 0, sizeof(Rank));
		for (int i = 0; i < 26; ++i)
			set[i] = i;
		while (n--) {
			scanf("%s", input);
			char begin = input[0];
			char end = input[strlen(input) - 1];
			++inDeg[begin - 'a'];
			++outDeg[end - 'a'];
			int pBegin = setFind(begin - 'a');
			int pEnd = setFind(end - 'a');
			if (pBegin != pEnd) {
				setUnion(pBegin, pEnd);
				--part;
			}
		}
		vector<int> d;
		for (int i = 0; i < 26; ++i) {
			if (!inDeg[i] && !outDeg[i])
				--part;
			else if (inDeg[i] != outDeg[i])
				d.push_back(abs(inDeg[i] - outDeg[i]));
		}
		if (part == 1 && (d.empty() || (d.size() == 2 && d[0] == 1)))
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
}