class Solution {
private:
    double total_hour(vector<int> & piles, int speed) {
        double hour = 0;
        for (int p: piles) {
            hour += (p+speed -1)/speed;
        }

        return hour;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low)/2;

            if (total_hour(piles, mid) <= h ) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
