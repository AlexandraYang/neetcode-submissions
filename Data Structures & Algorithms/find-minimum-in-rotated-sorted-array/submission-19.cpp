class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l +(r-l)/2;

            if (nums[mid] <= nums[r]) {
                // 3,4,5,6,1,2
                // F F F F T T
                //代表 左半才是sorted
                r = mid; // 保留 mid
            } else {
                //右半才是sorted 但要跳過mid 
                l = mid + 1;
            }   
        }

        return nums[l];
    }
};
