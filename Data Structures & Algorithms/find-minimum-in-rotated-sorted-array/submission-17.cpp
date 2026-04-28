class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        // 找第一個小魚的數字
        // 3,4,5,6,1,2
        // F F F F T T
        while (l < r) {
            int mid = l + (r-l)/2;
            //這句是在找右半是否是sorted array 
            if (nums[mid] <= nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[l];
    }
};
