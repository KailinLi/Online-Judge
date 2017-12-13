#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 1000000 + 5;
char str[MAXN];
int next[MAXN];
void getNext(size_t length) {
    int k = -1, j = 0;
    ::next[0] = -1;
    while (j < length) {
        if (k == -1 || str[k] == str[j]) {
            ++k;
            ++j;
            ::next[j] = k;
        }
        else {
            k = ::next[k];
        }
    }
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (scanf("%s", str) && str[0] != '.') {
        size_t length = strlen(str);
        getNext(length + 1);
        if (!(length % (length - ::next[length]))) {
            printf("%lu\n", length / (length - ::next[length]));
        }
        else {
            printf("1\n");
        }
    }
}