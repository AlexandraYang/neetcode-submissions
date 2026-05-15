class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; //紀錄idx 
        vector<int> ans; // 紀錄val 

        for (int r = 0; r < nums.size(); ++r) {
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                //假設 新增的val 比dq 內的值還要大 那代表候選人dq的需要淘汰 
                dq.pop_back();
            }

            dq.push_back(r);

            while (!dq.empty() && dq.front() < r - k +1) {
                dq.pop_front(); //windows 移走以後 刪除掉前面的idx 

            }

            //當 window 成形才開始記答案
            if (r >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
