class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int edge =0;
        int maxReach = 0;
        for (int i =0; i < nums.size() -1 ; ++i) {

            maxReach = max(maxReach, nums[i]+i);
            if (i == edge) {
                jump++;
                edge = maxReach;

            }
        }

        return jump;
    }
};
