#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
int findStr(const string& input, size_t &i, string &key) {
	size_t begin = i;
	if (input.substr(begin, 3) != "{{ ") {
		++i;
		return -1;
	}
	begin += 3;
	while (begin < input.size() && input[begin] != ' ') {
		key += input[begin];
		++begin;
	}
	if (input.substr(begin, 3) != " }}") {
		++i;
		return -1;
	}
	begin += 3;
	return begin - i;
}
int main () {
std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int m, n;
	cin >> m >> n;
	if (cin.peek() == '\n')
		cin.ignore();
	vector<string> input;
	map<string, string> dict;
	while (m--)
	{
		string tmp;
		getline(cin, tmp);
		input.push_back(tmp);
	}
	while (n--) {
		string tmp;
		getline(cin, tmp);
		size_t i = 0;
		while (i < tmp.size()) {
			if (tmp[i] == ' ')
				break;
			++i;
		}
		string key, value;
		key = tmp.substr(0, i);
		value = tmp.substr(i + 1);
		dict.insert(make_pair(key, value.substr(1, value.size() - 2)));
	}
	for (vector<string>::iterator str = input.begin(); str != input.end(); ++str) {
		size_t i = 0;
		while (i < str->size()) {
			if ((*str)[i] == '{') {
				string key;
				int ret = findStr(*str, i, key);
				if (ret == -1) {
					continue;
				}
				else {
					map<string, string>::iterator findkey = dict.find(key);
					if (findkey != dict.end()) {
						str->replace(i, ret, findkey->second);
						i += (findkey->second).size();
					}
					else {
						str->replace(i, ret, "");
					}
				}
			}
			else {
				++i;
			}
		}
		cout << *str << endl;
	}
}