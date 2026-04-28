class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int speed = 1;
        while(1) {
            double total_time = 0;
            for (int pile: piles) {
                total_time += (pile + speed -1)/speed;
            }

            if (total_time <= h) {
                return speed;
            }

            speed++;
        }
    
        return speed;
    }
};
