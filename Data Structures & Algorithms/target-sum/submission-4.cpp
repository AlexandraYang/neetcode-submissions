class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        P - N = target
        P + N = S

        2P = target + S;
        P = (target+S)/2;
        */

        int sum = 0;
        for(int n : nums) {
            sum += n;
        }

        
        if (abs(target) > sum) {
            return 0;
        }

        if ((target+sum) % 2 != 0) {
            return 0;
        }

        // 必須要檢查前先檢查好
        int P = (target + sum)/2;


        vector<int> dp(P+1, 0);
        dp[0] = 1; //湊出0的方式只有一種

        // 我現在在決定「要不要用這個 num」
        for (auto & n : nums) {
            for (int i = P; i >=n; --i) {
                // 「現在我想知道：
                // 用目前看過的數字，
                // 能不能湊出總和 j？」
                dp[i] += dp[i-n];
            }
        }
        
        return dp[P];
    }
};
