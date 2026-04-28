class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        for (int i =0;i < heights.size(); ++i) {
            int left = i;
            int right = i;
            
            while (left > 0 && heights[left -1] >= heights[i]) {
                left --;
            }

            while (right < heights.size() -1 && heights[right + 1] > heights[i]) {
                right++;
            }

            max_area = max((right - left + 1) * heights[i], max_area);
        }

        return max_area;
    }
};
