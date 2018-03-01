#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
vector<vector<pair<int, int>>> indexes;
map<string, int> stringToIndex;
char input[90];
char article[1505][90];
int offset[105];
int lineOffset;
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int a_size = n;
	getchar();
	int articleCnt = 0;
	while (n--) {
		int lineCnt = 0;
		offset[++articleCnt] = lineOffset;
		while (true) {
			fgets(input, sizeof(input), stdin);
			if (!strcmp(input, "**********\n")) break;
			strcpy(article[lineOffset++], input);
			int pos = 0;
			int size = strlen(input) - 1;
			int before_pos = pos;
			while (pos < size) {
				while (!isalpha(input[pos]) && input[pos] != '\n')
					before_pos = ++pos;
				while (isalpha(input[pos]) && input[pos] != '\n')
					++pos;
				input[pos] = '\0';
				string p(input + before_pos);
				for (auto &i : p)
					i = tolower(i);
				auto find_i = stringToIndex.find(p);
				if (find_i == stringToIndex.end()) {
					indexes.push_back(vector<pair<int, int>>{make_pair(articleCnt, lineCnt)});
					stringToIndex[p] = indexes.size() - 1;
				}
				else {
					indexes[find_i->second].push_back(make_pair(articleCnt, lineCnt));
				}
				before_pos = ++pos;
			}
			++lineCnt;
		}
	}
	offset[++articleCnt] = lineOffset;
	scanf("%d", &n);
	getchar();
	vector<string> cmd;
	while (n--) {
		fgets(input, sizeof(input), stdin);
		cmd.clear();
		int pos = 0;
		int before_pos = pos;
		int size = strlen(input) - 1;
		while (pos < size) {
			while (input[pos] == ' ' && input[pos] != '\n')
				before_pos = ++pos;
			while (input[pos] != ' ' && input[pos] != '\n')
				++pos;
			input[pos] = '\0';
			cmd.push_back(string(input + before_pos));
			before_pos = ++pos;
		}
		if (cmd.size() == 1) {
			auto find_i = stringToIndex.find(cmd[0]);
			if (find_i == stringToIndex.end()) {
				printf("Sorry, I found nothing.\n==========\n");
			}
			else {
				vector<pair<int, int>> & v = indexes[find_i->second];
				int cnt = 0;
				map<int, set<int>> tmp;
				for (auto i : v) {
					tmp[i.first].insert(i.second);
				}
				for (auto i : tmp) {
					if (cnt != 0) printf("----------\n");
					++cnt;
					for (auto j : i.second)
						printf("%s", article[offset[i.first] + j]);
				}
				printf("==========\n");
			}
		}
		else if (cmd.size() == 2) {
			vector<bool> no_article(a_size, false);
			auto find_i = stringToIndex.find(cmd[1]);
			vector<pair<int, int>> & v = indexes[find_i->second];
			bool flag = false;
			for (auto i : v) {
				no_article[i.first - 1] = true;
			}
			int cnt = 0;
			for (int i = 0; i < a_size; ++i) {
				if (!no_article[i]) {
					flag = true;
					if (cnt != 0) printf("----------\n");
					++cnt;
					for (int pos = offset[i + 1]; pos < offset[i + 2]; ++pos) {
						printf("%s", article[pos]);
					}
				}
			}
			if (!flag) printf("Sorry, I found nothing.\n");
			printf("==========\n");
		}
		else {
			map<int, vector<int>> get1;
			map<int, vector<int>> get2;
			auto find_i = stringToIndex.find(cmd[0]);
			vector<pair<int, int>> & v1 = indexes[find_i->second];
			for (auto i : v1) get1[i.first - 1].push_back(i.second);
			find_i = stringToIndex.find(cmd[2]);
			vector<pair<int, int>> & v2 = indexes[find_i->second];
			for (auto i : v2) get2[i.first - 1].push_back(i.second);
			int cnt = 0;
			bool flag = false;
			if (cmd[1][0] == 'A') {
				for (int i = 0; i < a_size; ++i) {
					if (get1[i].size() > 0 && get2[i].size() > 0) {
						flag = true;
						set<int> tmp;
						for (auto l : get1[i]) tmp.insert(l);
						for (auto l : get2[i]) tmp.insert(l);
						if (cnt != 0) printf("----------\n");
						++cnt;
						for (auto l : tmp)
							printf("%s", article[offset[i + 1] + l]);
					}
				}
			}
			else {
				for (int i = 0; i < a_size; ++i) {
					if (get1[i].size() > 0 || get2[i].size() > 0) {
						set<int> tmp;
						flag = true;
						for (auto l : get1[i]) tmp.insert(l);
						for (auto l : get2[i]) tmp.insert(l);
						if (cnt != 0) printf("----------\n");
						++cnt;
						for (auto l : tmp)
							printf("%s", article[offset[i + 1] + l]);
					}
				}
			}
			if (!flag) printf("Sorry, I found nothing.\n");
				printf("==========\n");
		}
	}
}