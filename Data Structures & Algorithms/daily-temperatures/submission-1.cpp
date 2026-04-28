class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // idx = temp, val = diff temp
        stack<pair<int, int>> record; // pair: {temp, idx}

        for (int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];

            while (!record.empty() && t > record.top().first) {
                pair<int, int> tmp = record.top();
                record.pop();

                ans[tmp.second] = i - tmp.second;  // 假設用溫度當idx 可能會爆掉

            }

            record.push({t, i});
        } 

        return ans;
    }
};
