class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int segment = 0;
        for (int i = 0; i < nums.size(); ++i) {
            segment += (nums[i]);
            maxSum = max(maxSum , segment);
            if (segment < 0) {
                segment = 0;
            }
            

        }

        return maxSum;
    }
};
