#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int findID(map<set<int>, int> &setToID, vector<set<int>> &IDtoset, set<int> s) {
	map<set<int>, int>::iterator find_i = setToID.find(s);
	if (find_i != setToID.end()) {
		return find_i->second;
	}
	else {
		IDtoset.push_back(s);
		setToID[s] = IDtoset.size() - 1;
		return IDtoset.size() - 1;
	}
}

int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		map<set<int>, int> setToID;
		vector<set<int>> IDtoset;
		stack<int> s;
		char input[15];
		while (n--) {
			scanf("%s", input);
			if (input[0] == 'P') {
				s.push(findID(setToID, IDtoset, set<int>()));
			}
			else if (input[0] == 'D') {
				s.push(s.top());
			}
			else {
				set<int> s1 = IDtoset[s.top()];
				s.pop();
				set<int> s2 = IDtoset[s.top()];
				s.pop();
				set<int> tmpS;
				if (input[0] == 'U') {
					set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(tmpS, tmpS.begin()));
					s.push(findID(setToID, IDtoset, tmpS));
				}
				else if (input[0] == 'I') {
					set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(tmpS, tmpS.begin()));
					s.push(findID(setToID, IDtoset, tmpS));
				}
				else {
					s2.insert(findID(setToID, IDtoset, s1));
					s.push(findID(setToID, IDtoset, s2));
				}
			}
			printf("%lu\n", IDtoset[s.top()].size());
		}
		printf("***\n");
	}
}