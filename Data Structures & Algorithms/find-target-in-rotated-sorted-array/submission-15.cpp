class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while (l <= r) {

            int mid = l + (r-l)/2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] <= nums[r]) {
                //1. 右邊是sorted
                if (nums[mid] < target && target <= nums[r]) {
                    //真的在右邊 那左邊可忽略 
                    l = mid + 1;
                } else {
                    r = mid - 1;

                }
            } else {
                // 真的在左半 
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid -1; 
                } else {
                    l = mid +1;
                }
            }
        }
        return -1;
    }
};
