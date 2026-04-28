class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
        cost = [1, 2,3] 
        dp   = [0, 0, ],X
                1  2
                + ;+
                0  0
            ___________
            min(1, 2)=1 

        dp   = [0, 0, 1], X
        cost = [1, 2, 3]         
                   0  1
                   +  +
                   2  3
                   _____            
                min(2, 4)=2 <==== ans

        */
        if (cost.size()<= 2) {
            return min(cost[0], cost[1]);
        }

        int len = cost.size();
        vector<int> dp(len +1 , 0); 
        for (int i = 2; i <= len+1; ++i) {
            dp[i] = min(cost[i-2]+dp[i-2], cost[i-1]+dp[i-1]);
        }
        return dp[len];
    }
};
