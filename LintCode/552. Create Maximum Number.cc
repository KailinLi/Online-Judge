class Solution {
public:
    /**
     * @param nums1: an integer array of length m with digits 0-9
     * @param nums2: an integer array of length n with digits 0-9
     * @param k: an integer and k <= m + n
     * @return: an integer array
     */
	deque<int> getK1;
	deque<int> getK2;
	void getKNumber(vector<int> &nums, int k, deque<int> &getK) {
		int d = nums.size() - k;
		getK.clear();
		for (int i = 0; i < nums.size(); ++i) {
			while (d > 0 && !getK.empty() && getK.back() < nums[i]) {
				--d;
				getK.pop_back();
			}
			getK.push_back(nums[i]);
		}
		getK.resize(k);
	}
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        // write your code here
		vector<int> res;
		for (int i = 0; i <= k; ++i) {
			if (i > nums1.size() || k - i > nums2.size()) continue;
			getKNumber(nums1, i, getK1);
			getKNumber(nums2, k - i, getK2);
			vector<int> tmp;
			while (getK1.size() + getK2.size()) {
				deque<int> &getK = getK1 > getK2 ? getK1 : getK2;
				tmp.push_back(getK.front());
				getK.pop_front();
			}
			res = max(res, tmp);
		}
		return res;
    }
};