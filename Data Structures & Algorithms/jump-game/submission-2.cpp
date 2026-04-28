class Solution {
public:
   bool canJump(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); ++i) {
        // TODO: 什麼情況要 return false ?
        if (i > maxReach) {
            return false;
        }
        maxReach = max(maxReach , nums[i]+i);
    }

    return true;
}
};
