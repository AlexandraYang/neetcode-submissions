class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(int i = 0; i <= nums.size(); ++i) {
            missing ^= i;
        }

        //要注意邊界不一樣!!!
        for(int i = 0; i < nums.size(); ++i) {
            missing ^= nums[i];
        }

        return missing;
    }
};
