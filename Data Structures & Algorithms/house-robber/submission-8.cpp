class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        
        //======== edge case ======
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        //======== End of edge case =====

        for (int i = 0; i < nums.size(); ++i) {
            int tmp = max(nums[i]+rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }

        return rob2;
    }
};
