class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<bool> dp(n+1, false);
        dp[0] = true; // MUST!!!!空字串是否可以被成功拆解 
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; i > j ; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
