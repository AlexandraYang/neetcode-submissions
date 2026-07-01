class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //找第K大 
        //小到大 
        priority_queue<int, vector<int>, greater<>> q;
        for (int i = 0; i < nums.size(); ++i) {
            
            // 1 2 3 4 5 6 
            q.push(nums[i]);
            if (q.size() > k) {
                q.pop();
            }
        }

        return q.top();
    }
};
