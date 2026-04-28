class Solution {

private:
    vector<int> memo; // -1 未計算  0: false, 1: true
    bool dfs(string s, vector<string>& wordDict, int idx) {
        if (idx == s.length()) {
            return true;
        }

        if (memo[idx] != -1) {
            return memo[idx];
        }

       for (auto c: wordDict) {
            if (idx+c.length() <= s.length() && s.substr(idx,c.length()) == c) {
                if (dfs(s, wordDict, idx + c.length())) {
                    memo[idx] = 1;
                    return true;
                }
            }
       }

        memo[idx] = 0;
        return false;

    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.length(), -1);
        return dfs(s, wordDict, 0);
    }
};
