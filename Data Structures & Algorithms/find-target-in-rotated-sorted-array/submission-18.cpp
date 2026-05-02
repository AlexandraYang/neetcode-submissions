class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size() -1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if (nums[mid] == target) {
                return mid;
            }

// nums=[5,1,2,3,4]
// target=1
// mid = 2 
            if (nums[mid] <= nums[r]) {
                //假設 456123, ta = 2 mid = 1
                //右半sorted ?
                if (nums[mid] < target && target <= nums[r]) {
                    //真的在右邊
                    l = mid + 1;
                } else {
                    r = mid -1;
                }
            } else {
                //nums[l] < target < numd[mid]
                if (nums[l] <= target && target < nums[mid]) {
                    //假設真的在左邊 
                    r = mid-1;
                } else {
                    l = mid +1;
                }
            }
        }

        return -1;
    }
};
