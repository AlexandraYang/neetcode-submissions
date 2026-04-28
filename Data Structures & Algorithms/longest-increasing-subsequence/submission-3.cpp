class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp (n+1, 1);
        for (int i =0; i < nums.size(); ++i) {
            for (int j = 0; i > j ; ++j) {
                if (nums[i] > nums[j]) { // i 是現在 j 是過去，必須現在 > 過去
                    int candidate = dp[j] + 1;
                    if (dp[i] < candidate) {
                        dp[i] = max(dp[i], candidate);
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
