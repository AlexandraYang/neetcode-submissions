class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; //大到小
        for (int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
        }

        while (!pq.empty() && k-1 != 0) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};
