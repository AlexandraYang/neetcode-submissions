class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack <int> idx_stk; // store index which can map to heights
        int max_area = 0;
        for (int i = 0; i <= n; ++i) { // 在i == n 的時候 強制pop
            //假設當前的高度 比stack 存的idx對應到的height 還要矮，那就要準備計算當前stack 內那個height的面積了
            while (!idx_stk.empty() && (i == n || heights[i] < heights[idx_stk.top()])) {
                int calculate_height = heights[idx_stk.top()];
                idx_stk.pop();
                int width = idx_stk.empty() ? i : (i - idx_stk.top() - 1);// 左右邊界  因為兩邊都是不要，所以最後要-1

                max_area = max(max_area, width * calculate_height);

            }

            idx_stk.push(i);
        }

        return max_area;
    }
};
