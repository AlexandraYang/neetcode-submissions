class Solution {
private:
    // speed = pile/h;
    // h = pile/speed;
    int total_time (vector<int>& piles, int speed) {
        double t_time = 0.0;

        for (auto & p: piles) {
            t_time += (p +speed -1)/speed;
        }
        return t_time; 
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max_pile = *max_element(piles.begin(), piles.end());
        int l = 1 ;//slowest speed 
        int r = max_pile;

        while (l < r) {
            int mid = l + (r-l)/2;

            if (total_time(piles, mid) <= h) {
                //假設吃完的時間小於 h 
                //那代表當前r 速率很OK
                r = mid; 
            } else {
                //吃的速度太慢 
                l = mid + 1;
            }
        }

        return l;
    }
};
