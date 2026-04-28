class Solution {
private:
    int findFirst(vector<int>& nums, int target) {
        int l =0, r = nums.size() -1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (target <= nums[mid]) {
                //target 在左邊，我們要逼近左邊
                r = mid -1;
            } else {
                l = mid + 1;
            }

            if (target == nums[mid]) {
                ans = mid;
            }
        }

        return ans;
    }
    int findLast(vector<int>& nums, int target) {
        int l =0, r = nums.size() -1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (target >= nums[mid]) {
                //target 在右邊，我們要逼近右邊
                l = mid + 1;
            } else {
                r = mid -1;
            }

            if (target == nums[mid]) {
                ans = mid;
            }
        }

        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};