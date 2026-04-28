class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int speed = 1;
        while(1) {
            double t_time = 0;
            
            for (int p : piles) {
                t_time += (p+speed -1)/speed;

            }

            if (t_time <= h) {
                return speed;
            }

            speed++;

        }

        return speed;
    }
};
