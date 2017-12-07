#include <iostream>
#include <string>
#include <vector>
using namespace std;
string printEm(const string &input, int &i);
string printLink(const string &input, int &i) {
	string text;
	string link;
	++i;
	bool inputText = true;
	while (i < input.size()) {
		if (input[i] == ']') {
			i += 2;
			inputText = false;
			continue;
		}
		else if (input[i] == '_') {
			if (inputText) {
				text += printEm(input, i);
			}
			else {
				link += printEm(input, i);
			}
		}
		else if (input[i] == ')') {
			++i;
			break;
		}
		else {
			if (inputText) {
				text += input[i++];
			}
			else {
				link += input[i++];
			}
		}
	}
	return "<a href=\"" + link + "\">" + text + "</a>";
}
string printEm(const string &input, int &i) {
	string text;
	++i;
	while (i < input.size()) {
		if (input[i] == '[') {
			text += printLink(input, i);
		}
		else if (input[i] == '_') {
			++i;
			break;
		}
		else {
			text += input[i++];
		}
	}
	return "<em>" + text + "</em>";
}
void printLine(const string &input) {
	string res;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '_') {
			res += printEm(input, i);
			--i;
		}
		else if (input[i] == '[') {
			res += printLink(input, i);
			--i;
		}
		else {
			res += input[i];
		}
	}
	cout << res;
}
void transHead(vector<string> &input) {
	int count = 0;
	int i = 0;
	for (; i < input[0].size(); ++i) {
		if (input[0][i] == '#') {
			++count;
		}
		else
			break;
	}
	while (input[0][i] == ' ') ++i;
	cout << "<h" << count << ">";
	printLine(input[0].substr(i));
	cout << "</h" << count << ">" << endl;
}
void transParagraph(vector<string> &input) {
	cout << "<p>";
	printLine(input[0]);
	for (int i = 1; i < input.size(); ++i) {
		cout << endl;
		printLine(input[i]);
	}
	cout << "</p>" << endl;
}
void transList (vector<string> &input) {
	cout << "<ul>" << endl;
	for (int i = 0; i < input.size(); ++i) {
		int j = 1;
		while (input[i][j] == ' ') ++j;
		cout << "<li>";
		printLine(input[i].substr(j));
		cout << "</li>" << endl;
	}
	cout << "</ul>" << endl;
}
int main () {
	vector<string> input;
	string line;
	while (getline(cin, line)) {
		if (line == "" && !input.empty()) {
			if (input[0][0] == '*') {
				transList(input);
			}
			else if (input[0][0] == '#') {
				transHead(input);
			}
			else {
				transParagraph(input);
			}
			input.clear();
		}
		else {
			input.push_back(line);
		}
	}
	if (!input.empty()) {
		if (input[0][0] == '*') {
			transList(input);
		}
		else if (input[0][0] == '#') {
			transHead(input);
		}
		else {
			transParagraph(input);
		}
		input.clear();
	}
}