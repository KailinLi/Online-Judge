#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 30 + 5;
int field[MAXN][MAXN];
int row, column;
struct Point{
	int i;
	int j;
	int cnt;
	Point(int i, int j, int cnt):
		i(i), j(j), cnt(cnt) {}
};
vector<Point> vr;
vector<Point> vc;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> row >> column;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < row; ++i) {
		int cnt = 0;
		for (int j = 1; j <= column; ++j) {
			if (field[i][j] == field[i][j - 1]) {
				++cnt;
			}
			else {
				if (cnt > 1) {
					vr.push_back(Point(i, j, cnt));
				}
				cnt = 0;
			}
		}
	}
	for (int j = 0; j < column; ++j) {
		int cnt = 0;
		for (int i = 1; i <= row; ++i) {
			if (field[i][j] == field[i - 1][j]) {
				++cnt;
			}
			else {
				if (cnt > 1) {
					vc.push_back(Point(i, j, cnt));
				}
				cnt = 0;
			}
		}
	}
	for (vector<Point>::iterator i = vr.begin(); i != vr.end(); ++i)
	{
		for (int j = 0; j < i->cnt + 1; ++j) {
			field[i->i][i->j - j - 1] = 0;
		}
	}
	for (vector<Point>::iterator i = vc.begin(); i != vc.end(); ++i) {
		for (int j = 0; j < i->cnt + 1; ++j) {
			field[i->i - j - 1][i->j] = 0;
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}