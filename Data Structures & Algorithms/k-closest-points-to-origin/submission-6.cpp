class Solution {
private: 
    priority_queue<pair<int, pair<int, int>>>q;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];

            pair<int, pair<int, int>> cur;
            cur = {x*x+y*y, {x,y}};
            q.push(cur);
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<vector<int>> result;

        while(!q.empty()) {
            result.push_back({q.top().second.first, q.top().second.second});
            q.pop();
        }

        return result;
    }
};
