class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // save idx
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < heights.size(); ++i) {
            
            //當發現loop下去後 heights 有比我stack內idx對應到的height 高
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top(); //須小心邊界 
                int width = (i - left) - 1;

                maxArea = max(maxArea, width * h);
            }

            st.push(i); // 發現loop到的i 沒有比我st內對應到的height 更高 就直接push
        } 

        //還留在 stack 裡的人 =「從來沒遇到比自己矮的右邊界」
        //
        while(!st.empty()) {
            //這個柱子「人生結束」
            int h = heights[st.top()];
            st.pop();

            //找左邊界
            int left = st.empty() ? -1:st.top();
            int width = (n - left) - 1; // 他們右邊界是 n

            maxArea = max(maxArea, width * h);
        }

        return maxArea;
    }
};
