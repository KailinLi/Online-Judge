#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;
const int MAXN = 10000 + 10;
int postOrder[MAXN];
int inOrder[MAXN];
int lch[MAXN];
int rch[MAXN];
int p_size, i_size;
int min_sum = 0x3f3f3f3f;
int min_node = 0x3f3f3f3f;
int make_tree(int i_left, int i_right, int p_left, int p_right) {
	if (i_left > i_right) return 0;
	int tmp_root = postOrder[p_right];
	int i = i_left;
	for (; i <= i_right; ++i) {
		if (inOrder[i] == tmp_root)
			break;
	}
	lch[tmp_root] = make_tree(i_left, i - 1, p_left, p_left + i - i_left - 1);
	rch[tmp_root] = make_tree(i + 1, i_right, p_left + i - i_left, p_right - 1);
	return tmp_root;
}
void DFS(int u, int sum) {
	sum += u;
	if (lch[u] == 0 && rch[u] == 0) {
		if (sum < min_sum || (sum == min_sum && u < min_node)) {
			min_node = u;
			min_sum = sum;
		}
	}
	if (lch[u]) DFS(lch[u], sum);
	if (rch[u]) DFS(rch[u], sum);
}
int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string in, post;
	while (getline(cin, in) && getline(cin, post)) {
		stringstream ss(in);
		int tmp;
		while (ss >> tmp)
			inOrder[i_size++] = tmp;
		ss = stringstream(post);
		while (ss >> tmp)
			postOrder[p_size++] = tmp;
		min_sum = 0x3f3f3f3f;
		min_node = 0x3f3f3f3f;
		make_tree(0, i_size - 1, 0, p_size - 1);
		DFS(postOrder[p_size - 1], 0);
		printf("%d\n", min_node);
	}
}