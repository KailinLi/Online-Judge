#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 1000;
int nextArray[MAXN];

void makeNext(char *p, int length) {
	nextArray[0] = -1;
	int j = 0, k = -1;
	while (j < length - 1) {
		if (k == -1 || p[j] == p[k])
			nextArray[++j] = ++k;
		else
			k = nextArray[k];
	}
}
int KMP(char * s , char * p) {
	int i = 0, j = 0;
	int slen = strlen(s), plen = strlen(p);
	makeNext(p, plen);
	while (i < slen && j < plen) {
		if (j == -1 || s[i] == p[j]) {
			++i;
			++j;
		}
		else
			j = nextArray[j];
	}
	if (j == plen)
		return i - j;
	else
		return -1;
}

int main () {
	std::ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	char s[] = "BBC ABCDAB ABCDABCDABDE";
	char p[] = "ABCDABD";
	printf("%d\n", KMP(s, p));
}