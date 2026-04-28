class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);

        stack<pair <int, int>> record; // degree, idx
        for (int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];
            while(!record.empty() && record.top().first < t) { // 這不能有等於 因為這樣會把下一個依樣DEGREE的當成下一個高溫
                //假設發現當前溫度大於stack 內的，就一直pop
                auto tmp = record.top();
                record.pop();
                // 且把idx 差異記錄下去
                ans[tmp.second] = i - tmp.second;
            }

            record.push({t, i});
        }

        return ans;
    }
};
