#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int field[15][10];
int input[4][4];
int rowOffset;
int base[4];
int fromBase(int column) {
	for (int i = 0; i < 15; ++i) {
		if (field[i][column])
			return i;
	}
	return 15;
}
int fromInput(int column) {
	for (int i = 3; i >= 0; --i) {
		if (input[i][column])
			return 3 - i;
	}
	return 4;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> input[i][j];
		}
	}
	cin >> rowOffset;
	for (int i = 0; i < 4; ++i) {
		base[i] = fromBase(rowOffset + i - 1) + fromInput(i);
	}
	sort(base, base + 4);
	int offset = base[0];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (input[i][j]) {
				field[offset - 3 - 1 + i][rowOffset + j - 1] = 1;
			}
		}
	}
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}