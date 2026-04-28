class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n: nums) {
            sum += n;
        }

        if (abs(target) > sum) {
            return 0;
        }

        if ((target+sum) % 2 != 0) {
            return 0;
        }

        int P = (target+sum)/2;
        vector<int> dp(P+1, 0);

        dp[0] = 1;

        for (int num: nums) {
            for (int j = P; j >= num; --j) {
                dp[j] += dp[j-num];
            }
        }

        return dp[P];
    }
};
