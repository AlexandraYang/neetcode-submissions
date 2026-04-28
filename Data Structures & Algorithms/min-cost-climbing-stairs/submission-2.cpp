class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = cost.size() -3; i >= 0; i--) {
            cost[i] = min(cost[i]+cost[i+1], cost[i]+cost[i+2]);
        }

        return min(cost[1], cost[0]);
    }
};
