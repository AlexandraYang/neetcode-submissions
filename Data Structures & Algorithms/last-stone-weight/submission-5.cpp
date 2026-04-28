class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq; //big ->small


        for (auto c: stones) {
            pq.push(c);
        }

        while (pq.size() > 1) {
            int x = pq.top();//first
            pq.pop();
            int y = pq.top(); //second
            pq.pop();

            if ( x == y) {
                
            } else if (x > y) {
                pq.push(x-y);
            }


        }

        return pq.size()>=1 ? pq.top() : 0;
    }
};
