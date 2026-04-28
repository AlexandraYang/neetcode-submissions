class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto & c: nums) {
            sum += c;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum /2 ;
        vector<bool> dp(target, false);

        dp[0] = true; //base case: 不選任何數字就可以湊出0了
        for (auto & num: nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
                //在湊出i數字以前，我是否可以找到dp[2]
            }
        }
       
       return dp[target];
    }
};
