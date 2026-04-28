class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+2, 1);

        //新陣列 前後補1, 且把nums arr 一個一個往arr 複製
        for (int i = 0; i < n; ++i) {
            arr[i+1] = nums[i];
        }

        //更新 n 因為長度現在左右各加一了
        n += 2;


        vector<vector<int>> dp(n, vector<int> (n,0));

        
        for (int len = 2; len < n; len++) {
            // 枚舉左端點
            for (int left =0; left+len < n; left++) {
                int right = left + len;

                //枚舉最後一科被戳的氣球
                // k 必須在 left, right 中間
                for (int k = left+1; k < right; ++k) {
                    dp[left][right] = max(
                        dp[left][right], 
                        dp[left][k] + dp[k][right] + 
                        arr[left]*arr[k]*arr[right]);
                }
            }
        }

        return dp[0][n-1];
    }
};
