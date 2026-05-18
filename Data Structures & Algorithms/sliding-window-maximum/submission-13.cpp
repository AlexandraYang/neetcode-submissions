class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int r = 0; r < nums.size(); ++r) {
            //後面的人假設比前面candidate 的人還要大
            //那就要把他們remove 
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            //當r 開始大於k個的時候 
            while(!dq.empty() && dq.front() < r - k +1) {
                dq.pop_front();
            }

            if (r >= k-1) {
                ans.push_back(nums[dq.front()]);
            }   
        }

        return ans;
    }
};
