class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int new_start = intervals[0][0];
        int new_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (new_end >= intervals[i][0]) {
                new_end = max(new_end, intervals[i][1]);
            } else {
                //完全沒overlapping
                ans.push_back({new_start, new_end});
                new_start = intervals[i][0];
                new_end = intervals[i][1];
                
            }
        }

        ans.push_back({new_start, new_end});

        return ans;
    }
};
