class Solution {
private: 
    priority_queue<pair<int, pair<int, int>>> q;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (int i = 0; i < points.size(); ++i) {
            
            int x = points[i][0];
            int y = points[i][1];


            pair<int, int> tmp;
            tmp.first = x;
            tmp.second = y;
            pair<int, pair<int, int>> buf;
            
            buf = {x*x+y*y, tmp};

            //先push 再shrink 
            q.push(buf);
            if (q.size() > k) {
                q.pop();
            }
            
        }

        // take out all element from heap 
        vector<vector<int>> result;
        while (!q.empty()) {
            // priority_queue<pair<int, pair<int, int>>> q;
            result.push_back({q.top().second.first, q.top().second.second});
            q.pop();
        }
        return result;


    }
};
