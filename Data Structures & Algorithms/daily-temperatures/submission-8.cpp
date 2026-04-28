class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st; // 
        for (int i =0; i < temperatures.size(); ++i) {
            //假設當前溫度 比 stack中的都還要熱
           while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top(); //上次最熱的那天 是第幾天 取出來
                st.pop();

                ans[prev] = i - prev; //更新到ans 去
           }
           st.push(i);
        }

        return ans;
    }
};
