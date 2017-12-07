#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 1000 + 5;
int target[MAXN];
int main () {
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int range;
	while (cin >> range && range != 0) {
		while (true) {
			if (cin >> target[0] && !target[0]) {
				cout << endl;
				break;
			}
			for (int i = 1; i < range; ++i) {
				cin >> target[i];
			}
			stack<int>s;
			int A = 1, B = 1;
			bool flag = false;
			while (B <= range) {
				if (A == target[B - 1]) {
					++A;
					++B;
				}
				else if (!s.empty() && s.top() == target[B - 1]) {
					s.pop();
					++B;
				}
				else if (A <= range) {
					s.push(A++);
				}
				else {
					flag = true;
					break;
				}
			}
			cout << (flag ? "No" : "Yes") << endl;
		}
	}
}