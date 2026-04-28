class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (const string& word : dict) {
                int len = word.size();
                if (i >= len &&
                    dp[i - len] &&
                    s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
