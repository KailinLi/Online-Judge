#include <iostream>
#include <cstring>
#include <map>
#include <climits>
#include <limits>
using namespace std;

int main () {
std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	map<int, int> reader;
	int size = INT_MIN;
	// cout << size << endl;
	cin >> size;
	while (size--) {
		int number = numeric_limits<int>::max();
		cin >> number;
		map<int, int>::iterator f = reader.find(number);
		if (f == reader.end()) {
			reader.insert(make_pair(number, 1));
			cout << 1 << " ";
		}
		else {
			++(f->second);
			cout << (f->second) << " ";
		}
	}
	cout << endl;
}