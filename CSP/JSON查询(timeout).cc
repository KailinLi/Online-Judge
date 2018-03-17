#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int MAXN = 100 * 80 + 5;
char input[MAXN];
int n, m;
int p;
char q[80 + 5];
map<string, string> res;
int getStr(string &s){
	if (input[p] != '\"') return -1;
	++p;
	int i = p;
	while (input[i] != '\"') {
		if (input[i] == '\\') {
			s.push_back(input[i + 1]);
			++i;
		}
		else s.push_back(input[i]);
		++i;
	}
	return ++i;
}
void json(string pa) {
	if (input[p] != '{') return;
	++p;
	while (input[p] != '}') {
		while (input[p] == ' ') ++p;
		string key;
		p = getStr(key);
		while (input[p] == ' ' || input[p] == ':') ++p;
		if (input[p] == '\"') {
			string value;
			p = getStr(value);
			res[pa + key] = value;
			while (input[p] == ' ' || input[p] == ',') ++p;
		}
		else {
			res[pa + key] = "fuck";
			json(pa + key + ".");
			while (input[p] == ' ' || input[p] == ',') ++p;
		}
	}
	++p;
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	getchar();
	fgets(input, 80 + 1, stdin);
	REP(i, n - 1) {
		int l = strlen(input);
		fgets(input + l - 1, 80 + 1, stdin);	
	}
	p = 0;
	json("");
	string q;
	while (m--) {
		fgets(::q, 80 + 1, stdin);
		::q[strlen(::q) - 1] = '\0';
		map<string, string>::iterator f = res.find(::q);
		if (f == res.end())
			printf("NOTEXIST\n");
		else {
			if (f->second == "fuck") {
				printf("OBJECT\n");
			}
			else {
				printf("STRING %s\n", f->second.c_str());
			}
		}
	}
	return 0;
}