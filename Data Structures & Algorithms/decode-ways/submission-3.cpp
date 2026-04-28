class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            //即使題目長度s 至少1, 但也有空字串 0的可能性
            return 0;
        }

        vector<int> dp(s.length()+1, 0); //寶留一個給idx = 0的位置
        dp[0] = 1; //空字串也是一種
        dp[1] = 1; //第一個字符 也是一種
        for (int i = 2; i <= s.length(); ++i) { // 從idx 2 開始
            //取第一位
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] -'0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }

        }

        return dp[s.length()];
    }
};
