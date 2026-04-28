class Solution {
private:
    void dfs(vector<vector<int>> &ans, vector<int>&seg, int start, int accum, int target, vector<int>& candidates) {
        if (target == accum) {
            ans.push_back(seg);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            //去重複: 同層不能選到相同元素
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }

            seg.push_back(candidates[i]);
            dfs(ans, seg, i+1, candidates[i]+accum, target, candidates);
            seg.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> seg;

        sort(candidates.begin(), candidates.end());
        dfs(ans, seg, 0, 0, target, candidates);

        return ans;
    }
};
