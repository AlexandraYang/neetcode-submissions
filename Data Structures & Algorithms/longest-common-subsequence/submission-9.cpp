class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        //dp[i][j] 分別代表text1 第i以前 跟 text2 第j以前 的LCS是多少
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i =1;i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // text1 前i 和 text2 前j個 假設長一樣的話，代表dp[i][j] 這LCS 可以在dp[i-1][j-1]基礎上加1
                if (text1[i-1] == text2[j-1]) {
                    //ex.g: 在前 3 個字元裡，最後新加進來的是誰？
                    // 那勢必為 2! 也就是 i -1.
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {    
                    //假設不一樣的話
                    //必須從text1[i-1] or text2[j-1] 選一個LCS最大的
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        //dp 看的前 m 個 跟 前 n 個
        //就是text1的[m-1] 和 text2[n-1]
        return dp[m][n];
    }
};
