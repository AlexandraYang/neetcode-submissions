class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // end time 由小到大
        sort(intervals.begin(), intervals.end(),
            [](auto& a, auto& b) {return a[1] < b[1];});


        // 小 ----------------------------大
        // {s1,      e1} 
        //     {intervals[i][0]         intervals[i][1]}
        int end = intervals[0][1];
        int cnt = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                cnt++;
            } else {
                end = intervals[i][1];
            }

        }

        return cnt;
        // 
        // intervals=[,[,,]
        // [1,11] [1,100] [2,12] 11,22]

    }
};
