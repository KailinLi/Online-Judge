#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int size;
void read(const string &input, string &str, size_t &i) {
	while (i < input.size() && input[i] != '/') {
		str += input[i];
		++i;
	}
	++i;
}
string input;
vector<string> current;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> size;
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	getline(cin, input);
	size_t i = 1;
	while (i < input.size()) {
		string get;
		read(input, get, i);
		if (!get.empty())
			current.push_back(get);
	}
	while (size--) {
		// input.clear();
		getline(cin, input);
		i = 1;
		vector<string> currentPath;
		if (!input.empty())
		{
			if (input[0] != '/') {
				i = 0;
				currentPath = current;
			}
		}
		else {
			currentPath = current;
		}
		while (i < input.size()) {
			string get;
			read(input, get, i);
			if (get == "." || get.empty())
				continue;
			else if (get == "..") {
				if (!currentPath.empty())
					currentPath.pop_back();
			}
			else {
				currentPath.push_back(get);
			}
		}
		if (currentPath.empty()) {
			cout << "/" << endl;
			continue;
		}
		else {
			for (size_t i = 0; i < currentPath.size(); ++i) {
				cout << "/" << currentPath[i];
			}
		}
		cout << endl;
	}
}