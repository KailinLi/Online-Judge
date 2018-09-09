class Solution {
public:
    int res;
    void merge_sort(int b, int e, vector<int> &data, vector<int> &tmp) {
        if (e - b <= 1) return;
        int mid = b + (e - b) / 2;
        merge_sort(b, mid, data, tmp);
        merge_sort(mid, e, data, tmp);
        int i = b, j = mid;
        int cnt = 0;
        while (i < mid || j < e) {
            if (j >= e || (i < mid && data[i] <= data[j])) tmp[cnt++] = data[i++];
            else {
                tmp[cnt++] = data[j++];
                res += (mid - i) % 1000000007;
                res %= 1000000007;
            }
        }
        for (int i = 0; i < cnt; ++i) data[b + i] = tmp[i];
    }
    int InversePairs(vector<int> data) {
        vector<int> tmp(data.size(), 0);
        res = 0;
        merge_sort(0, data.size(), data, tmp);
        return res;
    }
};