class Solution {
private:
    double estimate_time(vector<int>& piles, int mid) {
        double estimate_time = 0;
        for (auto p: piles) {
            estimate_time += (p + mid - 1)/mid;
        }   

        return estimate_time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()); //找最大speed

        // find 1st speed, thus it would be 
        while (l < r) {
            int mid = l + (r-l)/2;
            if (estimate_time(piles, mid) <= h) {
                //total estimate time is lesser than target time
                // 代表 目前 速度可行 但應該還有更小speed的，要往左找
                r = mid;
            } else {
                //目前speed 不行太慢，要往右
                // r = mid（保留 mid）
                // l = mid + 1（丟掉 mid）
                l = mid +1;
            }
        }

        return l;
    }
};
