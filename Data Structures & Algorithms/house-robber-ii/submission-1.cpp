class Solution {
private:
    int robHelper(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;

        for (int i = start; i < end; ++i) {
            int tmp = max(nums[i]+rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }

        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() ==1) {
            return  nums[0];
        }

        return max(robHelper(nums, 0, nums.size()-1), robHelper(nums, 1, nums.size()));
    }
};
