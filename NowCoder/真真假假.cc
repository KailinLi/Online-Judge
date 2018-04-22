#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
const int INF = 0x3f3f3f3f;
set<string> head = {
"algorithm", "bitset", "cctype", "cerrno", "clocale", "cmath", "complex", "cstdio", "cstdlib", "cstring", "ctime", "deque", "exception", "fstream", "functional", "limits", "list", "map", "iomanip", "ios", "iosfwd", "iostream", "istream", "ostream", "queue", "set", "sstream", "stack", "stdexcept", "streambuf", "string", "utility", "vector", "cwchar", "cwctype"
};
int n;
int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n); getchar();
    string in;
    while (n--) {
        cin >> in;
        if (head.find(in) != head.end()) printf("Qian\n");
        else printf("Kun\n");
    }
    return 0;
}