class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if (nums[mid] == target) {
                return mid;
            }

            // 右半是 sort過的話 
            if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && target <= nums[r]) {
                    //假設真的在右邊 
                    l = mid + 1;
                } else {
                    r = mid -1;
                }
            } else {
                //左半是sort 過 
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid -1 ;
                } else {
                    l = mid +1;
                }
            }
        }

        return -1;

    }
};
