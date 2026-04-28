class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;

        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[r]) {
                // 因為大於 所以勢必 最小值在右邊
                //左邊掰掰
                l = mid + 1;
            } else {
                //第一次 因為mid = 3 ->1
                // 1 沒有大於4 那勢必最小是在右邊
                r = mid;

            }
        }

        return nums[l];
    }
};
