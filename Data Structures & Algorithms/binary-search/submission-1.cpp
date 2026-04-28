class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        while (left <= right) {
            // 防止整數溢位
            int mid = left + (right - left)/2;
            
            if (nums[mid] == target) {
                return mid; // find it
            } else if (nums[mid] > target) {
                right = mid -1; // 去左邊找
            } else {
                left = mid +1;// 去右邊找
            }
        }

        return -1;
    }
};
