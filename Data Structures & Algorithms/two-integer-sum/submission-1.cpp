class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int > tbl; // key:數字, value:索引
        vector <int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            if (tbl.find(tmp) != tbl.end()) {
                ans.push_back(tbl[tmp]);
                ans.push_back(i);
                return ans;
            }

            tbl[nums[i]] = i;
        }

        return ans;
    }
};
