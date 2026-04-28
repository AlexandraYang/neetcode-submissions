class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //Input: points = [[0,2],[2,2]], k = 1
        // Output: [[0,2]]

        //那我要設計一個priority queue, 裡面存 pair<distance, idx>
        // minHeap

        // minHeap: (distance, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        
        for (int i = 0 ;i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            int dist = x*x + y*y;
            minHeap.push({dist, i});
        }

        vector<vector<int>> ans;
        for (int i = 0; i< k; ++i) {
            pair<int, int> tmp = minHeap.top();
            minHeap.pop();
            ans.push_back(points[tmp.second]);
        }

        return ans;
    
    }
};
