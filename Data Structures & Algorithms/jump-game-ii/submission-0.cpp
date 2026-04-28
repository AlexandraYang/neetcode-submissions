class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int maxReach = 0;
        int edge = 0;

        // 掃描「目前這一跳」能到達的所有位置
        for (int i = 0; i < n - 1; ++i) {
            maxReach = max(maxReach, i + nums[i]);

            //我已經把「這一跳能覆蓋的區間」全部看完了
            if (i == edge) {
                jumps ++;
                edge = maxReach;
            }
        }

        return jumps;
    }
};
