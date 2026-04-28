class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += (gas[i] - cost[i]);
        }

        if (sum < 0) {
            return -1;
        }

        int total = 0;
        int res = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total += (gas[i] - cost[i]);

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
