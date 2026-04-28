class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 3,4,5,6,1,2
        int l = 0;
        int r = nums.size() -1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r-l)/2;
            
            if (nums[mid] == target) {
                return mid;
            }

            // 1,2,3,4,5,6
            //part 1: 找 右半還是左半是 sorted 
            if (nums[mid] <= nums[r]) { //這裡右半是sorted 
                
                // nums[mid] < target <= nums[r]
                // 意思：target 比 mid 大 && target 沒超過 r


               if (nums[mid] < target && target <= nums[r]  ) {
                    // 1. 右半是 sorted
                    // 2. target 在這個 sorted range
                    // 3. target 在一個已排序區間內，而且在 mid 右邊
                    // 4. mid 左邊全部不用看
                    // 5. mid 自己也不用看
                    l = mid + 1;
                } else {
                    // 1. 右半是 sorted
                    // 2. target 不在這個 sorted range
                    // 3. target 一定在另一半（左半）
                    r = mid - 1;
                }
            } else {
                // 左半sorted
                if (nums[l] <= target && target < nums[mid]) {
                    // 1. target 真的在第一層的左半
                    // 2. 那就不用管右邊了 
                    r = mid - 1;
                } else {
                    // 1. 左半是sorted 
                    // 2. target 不在這 左半 [l, mid) 所以踢去第一層的右半去
                    l = mid + 1;
                }
                
                
            }
        }

        return -1; //binary search 找不到時，不能回傳任何 index
    }
};
