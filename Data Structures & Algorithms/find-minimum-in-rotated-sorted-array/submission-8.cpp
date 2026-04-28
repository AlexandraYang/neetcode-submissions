class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;

        /*
        這題的 array 有一個性質：
          🔥 原本是遞增，經過「旋轉一次」
        整個 array 會變成兩段：
        [大的一段] + [小的一段]

        例如：[4,5,6,7] + [1,2,3]
        👉 最小值一定在「小的一段」
        */
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
