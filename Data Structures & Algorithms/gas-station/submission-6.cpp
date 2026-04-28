class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += (gas[i] - cost[i]);
        }

        if (sum < 0) {
            return -1; // return -1, 因為都不符合
        }

        int ans = 0;
        sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += (gas[i] - cost[i]);

            if (sum < 0) {
                sum = 0;
                ans = i + 1;
            }
        }

        return ans;
    }
};
