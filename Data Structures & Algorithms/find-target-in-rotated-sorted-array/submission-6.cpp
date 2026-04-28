class Solution {
public:
// 5671234 
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                return mid;
            }

            //重點!! 先判斷是否有序(由小到大)
            //這裡 <= 是因為 假設沒跨 pivot 
            // 那就是2345 沒問題；但假設是712的話
            // 7 <= 1 就不會成立會到part 2 去
            if (nums[left] <= nums[mid]) {
                //part 1: 
                //判斷target 是否在左半
                // 為何是 <= + <，因為 mid 本身非target, 上面判斷過了
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid -1;
                } else {
                    left = mid +1;
                }
            } else { //否則右半有序
                // part 2
                
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
