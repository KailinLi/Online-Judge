#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 1000;
int wa[MAXN], wb[MAXN], wv[MAXN], ww[MAXN];
inline bool cmp(int *r, int a, int b, int len) {
    return r[a] == r[b] && r[a + len] == r[b + len];  
}  
void da(int *str, int *sa, int n,int m) {  
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; ++i)
        ww[i] = 0;
    for(i = 0; i < n; ++i)
        ww[x[i] = str[i]]++;
    for(i = 1; i < m; ++i)
        ww[i] += ww[i-1];
    for(i = n - 1; i  >= 0; --i)
        sa[--ww[x[i]]] = i;
    for(j = p = 1; p < n; j <<= 1, m = p) {
        for(p = 0, i = n - j; i < n; ++i)
            y[p++]=i;
        for(i = 0; i < n; ++i)
            if(sa[i] >= j)
                y[p++] = sa[i] - j;
        for(i = 0; i < m; ++i)
            ww[i] = 0;
        for(i = 0; i < n; ++i)
            ww[wv[i] = x[y[i]]]++;
        for(i = 1; i < m; ++i)
            ww[i] += ww[i-1];
        for(i = n-1; i >= 0; --i)
            sa[--ww[wv[i]]] = y[i];
        for(t = x, x = y, y = t, x[sa[0]] = 0, p = i = 1; i < n; ++i)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
    }
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int r[100] = {'b', 'a', 'n', 'a', 'n', 'a', 0};
    int sa[100];
    da(r, sa, 7, 1000);
    for (int i = 0; i < 7; ++i) {
        cout << sa[i] + 1 << endl;
    }
}