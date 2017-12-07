#include <iostream>
#include <map>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	map<int32_t, int32_t> table;
	int32_t _begin, _end;
	while (cin >> _begin >> _end) {
		int32_t res = INT32_MIN;
		int32_t begin = _begin;
		int32_t end = _end;
		if (begin > end) swap(begin, end);
		for (int32_t current = begin; current <= end; ++current) {
			int32_t time = 0;
			int32_t i = current;
			while (i != 1) {
				auto find = table.find(i);
				if (find != table.end()) {
					res = max(res, time + find->second);
					break;
				}
				else {
					++time;
					if (i % 2) {
						i = i * 3 + 1;
					}
					else {
						i = i >> 1;
					}
				}
			}
			res = max(res, time + 1);
		}
		cout << _begin << " " << _end << " " << res << endl;
	}
}