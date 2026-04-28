class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int left = 0, right = height.size()-1;
        int max_left = 0;
        int max_right = 0;
        int total_water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= max_left) {
                    max_left = height[left];
                } else {
                    total_water += max_left - height[left];
                }

                left++;
            } else {
                if (height[right] >= max_right) {
                    // 如果当前柱子比右边最高柱子高，更新 max_right
                    max_right = height[right];
                } else {
                    // 否则，计算当前位置能接的雨水量并累加
                    total_water += max_right - height[right];
                }
                // 右指针向左移动
                right--;
            }
        }
        return total_water;
    }
};
