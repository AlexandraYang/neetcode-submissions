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


            //如果 x == y → stone disappears（不應該 push 0）
            if (x!=y) {
                q.push(x-y);
            }
            
        }

        return q.empty() ? 0: q.top();
    }
};
