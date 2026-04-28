class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int max_area = 0;
        while(l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            max_area = max(max_area, area);

            if (heights[l] > heights[r]) {
                //移動高度較小的那段
                r--;
            } else {
                l++;
            }
        }

        return max_area;
    }
};
