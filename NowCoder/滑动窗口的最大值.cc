class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < num.size(); ++i) {
            if (q.empty()) q.push_back(num[i]);
            else {
                if (i > size - 1 && num[i - size] == res.back()) q.pop_front();
                while (!q.empty() && q.back() < num[i]) q.pop_back();
                q.push_back(num[i]);
            }
            if (i >= size - 1) res.push_back(q.front());
        }
        return res;
    }
};