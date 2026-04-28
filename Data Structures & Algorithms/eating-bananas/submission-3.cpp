class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;
        while (left <= right) {
        
            int mid = left + (right-left)/2;

            long long totoal_hr_needed = 0;
            for (int i = 0; i < piles.size(); ++i) {
                // totoal_hr_needed += ceil(piles[i]/mid);
                 totoal_hr_needed += (piles[i] + mid - 1) / mid;
            }

            if (totoal_hr_needed <= h) {
                ans = mid; // mid 是可能的答案 但還可以更小的速度
                right = mid -1;
            } else {
                left = mid +1;
            }
        }

        return ans;
    }
};
