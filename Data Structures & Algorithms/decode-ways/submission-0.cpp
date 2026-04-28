class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0'); //注意!!!!
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2]; //因為取兩位 就要找兩位前的狀態
            }
        }

        return dp[n];
    }
};
