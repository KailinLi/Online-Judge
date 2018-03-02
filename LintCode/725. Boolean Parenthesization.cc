class Solution {
public:
    /*
     * @param symb: the array of symbols
     * @param oper: the array of operators
     * @return: the number of ways
     */
    vector<vector<pair<int, int>>> dp;
    void makeDP(int begin, int end, string &symb, string &oper) {
    	if (dp[begin][end].first != -1)
    		return;
    	else if (begin == end) {
    		dp[begin][end].first = (symb[begin] == 'T') ? 1 : 0;
    		dp[begin][end].second = (symb[begin] == 'F') ? 1 : 0;
    		return;
    	}
    	else if (begin + 1 == end) {
    		bool lhs = symb[begin] == 'T';
    		bool rhs = symb[end] == 'T';
    		if (oper[begin] == '&') dp[begin][end].first = (lhs && rhs) ? 1 : 0;
    		else if (oper[begin] == '|') dp[begin][end].first = (lhs || rhs) ? 1 : 0;
    		else dp[begin][end].first = ((lhs && !rhs) || (!lhs && rhs)) ? 1 : 0;
    		dp[begin][end].second = dp[begin][end].first ? 0 : 1;
    		return;
    	}
    	else {
    		int sum = 0;
    		int failSum = 0;
    		for (int i = begin; i < end; ++i) {
	    		makeDP(begin, i, symb, oper);
	    		makeDP(i + 1, end, symb, oper);
	    		pair<int, int> &lhs = dp[begin][i];
	    		pair<int, int> &rhs = dp[i + 1][end];
	    		if (oper[i] == '&') {
	    			sum += lhs.first * rhs.first;
	    			failSum += lhs.second * rhs.first + rhs.second * lhs.first + lhs.second * rhs.second;
	    		}
	       		else if (oper[i] == '|') {
	    			sum += lhs.first * rhs.second + rhs.first * lhs.second + lhs.first * rhs.first;
	    			failSum += lhs.second * rhs.second;
	    		}
	    		else {
	    			sum += lhs.first * rhs.second + lhs.second * rhs.first;
	    			failSum += lhs.first * rhs.first + lhs.second * rhs.second;
	    		}
	    	}
	    	dp[begin][end].first = sum;
	    	dp[begin][end].second = failSum;
	    	return;
    	}
    }
    int countParenth(string &symb, string &oper) {
    	for (int i = 0; i < symb.size(); ++i)
    		dp.push_back(vector<pair<int, int>>(symb.size(), make_pair(-1, -1)));
    	makeDP(0, symb.size() - 1, symb, oper);
    	return dp[0][symb.size() - 1].first;
    }
};