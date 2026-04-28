class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++ i) {
            int tmp = target - nums[i];

            // there will be only one solution
            if (map.find(tmp) != map.end()) {
                ans.push_back(map[tmp]); // 取得 tmp 這個值在 nums 中的索引
                ans.push_back(i);         // 目前數字的索引
                return ans;
            }

            map[nums[i]] = i;
        }

        return ans;
    }
};
