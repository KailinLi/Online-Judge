#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
void getString(string &res, string &s, int &i) {
	++i;
	while (i < s.size()) {
		if (s[i] == '\\') {
			res += s[++i];
		}
		else if (s[i] == '\"') {
			++i;
			break;
		}
		else {
			res += s[i];
		}
		++i;
	}
}
void getObject(map<string, string> &res, string &key, string &s, int &i) {
	++i;
	bool readKey = true;
	string currentKey;
	while (i < s.size()) {
		if (s[i] == '\"') {
			string str;
			getString(str, s, i);
			if (readKey) {
				currentKey = key + ((key.empty()) ? "" : ".") + str;
			}
			else {
				res[currentKey] = str;
			}
		}
		else if (s[i] == ':') {
			readKey = false;
			++i;
		}
		else if (s[i] == '{') {
			res[currentKey] = "";
			getObject(res, currentKey, s, i);
		}
		else if (s[i] == ',') {
			readKey = true;
			++i;
		}
		else if (s[i] == '}') {
			++i;
			break;
		}
		else {
			++i;
		}
	}
}
int main () {
	int n, m;
	cin >> n >> m;
	if (cin.peek() == '\n') cin.ignore();
	string json;
	for (int t = 0; t < n; ++t) {
		string tmp;
		getline(cin, tmp);
		json += tmp;
	}
	map<string, string> dict;
	string init;
	int i = 0;
	getObject(dict, init, json, i);
	// for (map<string, string>::iterator i = dict.begin(); i != dict.end(); ++i) {
	// 	cout << i->first << " " << i->second << endl;
	// }
	for (int i = 0; i < m; ++i) {
		string question;
		cin >> question;
		// cout << question << " *  ";
		map<string, string>::iterator find = dict.find(question);
		if (find == dict.end()) {
			cout << "NOTEXIST" << endl;
		}
		else if (find->second == "") {
			cout << "OBJECT" << endl;
		}
		else {
			cout << "STRING " << find->second << endl;
		}
	}
}