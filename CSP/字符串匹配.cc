#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(char lhs, char rhs) {
	return toupper(lhs) == toupper(rhs);
}
int main () {
std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string base;
	cin >> base;
	int sensitive;
	cin >> sensitive;
	int size;
	cin >> size;
	if (cin.peek() == '\n')
		cin.ignore();
	while (size--) {
		string input;
		getline(cin, input);
		if (sensitive) {
			if (search(input.begin(), input.end(), base.begin(), base.end()) != input.end())
				cout << input << endl;
		}
		else {
			if (search(input.begin(), input.end(), base.begin(), base.end(), cmp) != input.end())
				cout << input << endl;
		}
	}
}