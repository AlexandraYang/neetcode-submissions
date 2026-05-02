class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() -1; //假設這裡是nums.size(), 那必定 line 10 會出界線

        while (l < r) {
            int mid = l + (r-l)/2;

            //nums[r] 一定越界, 若r = nuums.size()
            // 只要你需要用 nums[r]，就絕對不能寫 r = n
            if (nums[mid] <= nums[r]) { 
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[l];
    }
};
