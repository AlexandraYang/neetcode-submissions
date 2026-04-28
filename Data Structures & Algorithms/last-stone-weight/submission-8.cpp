class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for (int i = 0; i < stones.size(); ++i) {
            pq.push(stones[i]);
        } 

        while(pq.size() > 1) {
            int tmp1 = pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();

            if (tmp1 != tmp2) {
                pq.push(tmp1 - tmp2);
            }

        }

        return pq.empty() ? 0 : pq.top(); 
    }
};
