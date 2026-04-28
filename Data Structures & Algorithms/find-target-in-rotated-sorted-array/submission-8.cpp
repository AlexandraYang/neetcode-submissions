class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;

        // find target use 3 times if-else template
        while (l <= r) {
            int mid = l + (r-l)/2;

            if (target == nums[mid]) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {
                //左半sorted 
                if (nums[l] <= target && target < nums[mid]) {
                    //代表 左半真的有答案，右邊要drop
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }

            } else {
                //右半sorted 
                if (nums[mid] < target && target <= nums[r]) {
                    // 假設真的在右半
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
