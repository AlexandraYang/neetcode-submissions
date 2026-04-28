class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() -1;
        int mid = 0;
        while (l < r) {
            int mid = l + (r-l)/2;

            if (nums[mid] <= nums[r]) {
                //假設 右邊比較大 
                // 那就 要往左邊找 但我應被這是lower bound template
                r = mid;
            } else {
                l = mid +1;
            }
        }

        return nums[l];
    }
};
