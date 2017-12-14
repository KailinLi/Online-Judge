#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 100000 + 5;
int wa[MAXN], wb[MAXN], wv[MAXN], ww[MAXN];

int Rank[MAXN], sa[MAXN], lcp[MAXN], dp[MAXN][20], tmpRes[MAXN];

char str[MAXN];

inline bool cmp(int *r, int a, int b, int len) {
    return r[a] == r[b] && r[a + len] == r[b + len];  
}
void da(char *str, int n, int m) {  
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
void getLcp(char *str, int n) {
    for (int i = 0; i <= n; ++i) {
        Rank[sa[i]] = i;
    }
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int j = sa[Rank[i] - 1];
        h ? h-- : 0;
        for (; j + h < n && i + h < n; ++h) {
            if (str[i + h] != str[j + h])
                break;
        }
        lcp[Rank[i] - 1] = h;
    }
}
void RMQ_init(int n) {
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = lcp[i - 1];
    }
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int RMQ(int left, int right) {
    left = Rank[left];
    right = Rank[right];
    if (left > right)
        swap(left, right);
    ++left;
    int k = 0;
    while ((1 << (k + 1)) <= right - left + 1)
        ++k;
    return min(dp[left][k], dp[right - (1 << k) + 1][k]);
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int count = 0;
    while (scanf("%s", str) && str[0] != '#') {
        int length = (int)strlen(str);
        da(str, length + 1, 'z' + 1);
        getLcp(str, length);
        RMQ_init(length);
        int maxMatch = -1;
        int cnt = 0;
        for (int len = 1; len <= length; ++len) {
            int match;
            for (int i = 0; i + len < length; i += len) {
                match = RMQ(i, i + len);
                int pos = i - (len - match % len);
                match = match / len + 1;
                if (pos >= 0 && RMQ(pos, pos + len) >= len)
                    ++match;
                if (maxMatch < match) {
                    maxMatch = match;
                    cnt = 0;
                    tmpRes[cnt++] = len;
                }
                else if (maxMatch == match && len != tmpRes[cnt - 1])
                    tmpRes[cnt++] = len;
            }
        }
        bool flag = false;
        for (int i = 1; i <= length && !flag; ++i) {
            for (int j = 0; j < cnt && !flag; ++j) {
                if (RMQ(sa[i], sa[i] + tmpRes[j]) >= tmpRes[j] * (maxMatch - 1)) {
                    str[sa[i] + tmpRes[j] * maxMatch] = '\0';
                    flag = true;
                    printf("Case %d: %s\n", ++count, str + sa[i]);
                }
            }
        }
    }
}