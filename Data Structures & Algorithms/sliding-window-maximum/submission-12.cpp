class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int r = 0; r < nums.size(); ++r) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            
            dq.push_back(r); // put in candidate's idx 

            // r; r -k + 1 (left boundary)
            // formed the windows
            while (!dq.empty() &&  dq.front() < r -k +1 ) {
                //windows 往後右邊滑 則需要檢查dq.front() 是否超過該區間
                dq.pop_front();
            }

            

            if (r >= k - 1) {
                //可想像 假設windows 是3,
                // 那就是r 從0開始到超過 idx = 2 的時候開始記錄
                //而且是要 用dq 維護的idx 對應到的nums 去塞進去ans! 
                ans.push_back(nums[dq.front()]);
            }
            
        }

        return ans;
    }
};
