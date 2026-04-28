class Solution {
private:
    // int total_time () {

    // }
public:

    // time * speed = pinlin
    // time = piles/speed; 
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        
        while (1) {
            double t_time = 0;

            for (int p : piles) {
                t_time += (p + speed -1)/speed;
            }

            if (t_time <= h) {
                return speed;
            }

            speed++;
        }

        // return speed;
    }
};
