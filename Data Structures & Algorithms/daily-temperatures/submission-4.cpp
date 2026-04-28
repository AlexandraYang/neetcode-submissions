class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> record;
        int n = temperatures.size();
        vector<int> ans(n, 0);


        for (int i = 0; i < temperatures.size(); ++i) {
            int cur_temp = temperatures[i];

            while(!record.empty() && cur_temp > temperatures[record.top()]) {
                int prev_idx = record.top();
                record.pop();

                ans[prev_idx] = i - prev_idx;
            }

            record.push(i);
        }

        return ans;
    }
};
