class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (1) {
            sort(stones.rbegin(), stones.rend()); // from big -> small 

            if (stones[1] == 0 || stones.size() == 1) {
                return stones[0];
            }

            int x = stones[0];
            int y = stones[1];

            if (x == y) {
                stones[0] = 0;
                stones[1] = 0;
            } else {
                stones[0] = x-y;
                stones[1] = 0;
            }
        }

        
    }
};
