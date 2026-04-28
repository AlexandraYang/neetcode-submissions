class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //越右邊越靠近終點
        //我計算的base 是靠右邊二數，然後慢慢往左的
        for (int i = cost.size() -3; i >= 0; i --) {
            cost[i] = min(cost[i]+cost[i+1], cost[i]+cost[i+2]);
        }

        return min(cost[1], cost[0]);
    }
};
