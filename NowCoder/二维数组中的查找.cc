class Solution {
public:
    bool divide_find(int x1, int x2, int y1, int y2, vector<vector<int> > &a, int val) {
        if (x1 >= x2 || y1 >= y2) return false;
        if (x1 + 1 == x2 && y1 + 1 == y2) return a[x1][y1] == val;
        int m1 = x1 + (x2 - x1) / 2;
        int m2 = y1 + (y2 - y1) / 2;
        if (a[m1][m2] == val) return true;
        else if (a[m1][m2] > val)
            return  divide_find(x1, m1, y1, m2, a, val) ||
                    divide_find(m1, m1 + 1, y1, m2, a, val) ||
                    divide_find(x1, m1, m2, m2 + 1, a, val);
        else return divide_find(m1 + 1, x2, y1, m2 + 1, a, val) ||
                    divide_find(x1, m1 + 1, m2 + 1, y2, a, val) ||
                    divide_find(m1 + 1, x2, m2 + 1, y2, a, val);
    }
    bool Find(int target, vector<vector<int> > array) {
        return divide_find(0, array.size(), 0, array.empty() ? 0 : array[0].size(), array, target);
    }
};