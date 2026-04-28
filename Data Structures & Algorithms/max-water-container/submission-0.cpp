class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() -1;
        int max_water = 0;
        while (left < right) {
            int h = min(heights[left], heights[right]);
            int w = right - left;

            max_water = max(max_water, h*w);
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }

        }
        return max_water;
    }
};
