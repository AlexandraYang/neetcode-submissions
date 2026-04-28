class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int maxReach = 0;
        for (int i = 0; i < len; ++i) {
            if (i > maxReach) {
                //i is always on the right of maxReach
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};
