class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                return mid;
            }

            //重點!! 先判斷是否有序(由小到大)
            if (nums[left] <= nums[mid]) {
                //判斷target 是否在左半
                // 為何是 <= + <，因為 mid 本身非target, 上面判斷過了
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid -1;
                } else {
                    left = mid +1;
                }
            } else { //否則右半有序
            
                // target 是否在右半? (mid, right)
                if (nums[mid] < target && target <= nums[right]) {
                    //target 在右半 ，搜右邊
                    left = mid +1;
                } else {
                    right = mid -1;
                }

            }
        }
        return -1;
    }
};
