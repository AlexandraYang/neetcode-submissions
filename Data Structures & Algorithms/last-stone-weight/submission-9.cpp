class Solution {
private: 
    priority_queue<int> q; // 由大到小 
public:
    int lastStoneWeight(vector<int>& stones) {

        for (int i = 0; i < stones.size(); ++i) {
            q.push(stones[i]);
        }
        

        while(q.size() >= 2) {
            int x = q.top(); q.pop(); //第一大 
            int y = q.top(); q.pop(); // 第二大 

            q.push(x-y);
        }

        return q.top();
    }
};
