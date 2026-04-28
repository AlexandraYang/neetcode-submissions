class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        int mid = 0;
        while (left < right) { // 此題屬於二元搜尋的第二種template 找極值的
            
            mid = left + (right - left)/2;
            if (nums[mid] < nums[right]) {
                //假設nums[mid] 比nums[right]更小的話，最小值一定在左側
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
