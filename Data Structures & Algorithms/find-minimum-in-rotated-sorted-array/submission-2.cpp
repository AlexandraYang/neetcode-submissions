class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() -1;

        while (left < right) {
            int mid = left + (right - left) /2;
            if (nums[mid] > nums[right]) {
                //if mid's num is bigger than nums[left]
                // 這樣寫會錯
                /* if (nums[left] < nums[mid]) {
                但是如果是原始未旋轉情況：
                nums = [1,2,3,4,5,6,7]
                left = 0, mid = 3, nums[left] = 1, nums[mid] = 4
                nums[left] < nums[mid] 成立，你會做 left = mid + 1，結果就會跳過正確最小值（因為它其實就在最左邊）
                */ 
                left = mid +1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};
