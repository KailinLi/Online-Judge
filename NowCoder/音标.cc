#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
char vowel[6] = {'y', 'u', 'o', 'i', 'e', 'a'};
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    char input;
    while (scanf("%c", &input) != EOF) {
        if (input == '\n') printf("\n");
        else {
            REP(i, 6) {
                if (vowel[i] <= input) {
                    printf("%c", vowel[i]);
                    break;
                }
            }
        }
    }
    return 0;
}