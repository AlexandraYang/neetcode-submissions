class Solution {

    /*
    Input: temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
    Output: [1,4,1,2,1,0,0]
    */
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(), 0);
        stack <int> max_stack; //record the idx
        for (int i= 0; i< temp.size(); ++i) {
            while (!max_stack.empty() && temp[i] > temp[max_stack.top()]) {
                int prev_idx = max_stack.top();
                max_stack.pop();
                ans[prev_idx] = i - prev_idx;
            }
            max_stack.push(i);
        }

        return ans;
    }
};
