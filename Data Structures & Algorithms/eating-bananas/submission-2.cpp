class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;// at least eat 1 banaba every hour
        int right = *max_element(piles.begin(), piles.end()); // piles 中最大那堆香蕉的數量
        int ans = right; // 初始化答案為最大可能速度，它一定能在 h 小時內吃完

        while (left <= right) {
            int mid = left + (right-left)/2;
            long long total_hours_needed = 0; // 注意：總小時數可能超出 int 範圍，建議使用 long long
            for (int i = 0; i < piles.size() ; ++i) {
                //  total_hours_needed += ceil(piles[i]/mid); //向上取值
                total_hours_needed += (piles[i] + mid - 1) / mid;
            }
            
            if (total_hours_needed <= h) {
                // 如果當前速度 'mid' 可以在 h 小時內吃完 (或更快)
                // 說明 'mid' 是一個可能的答案，但我們可能可以找到更小的速度。
                ans = mid;         // 儲存 'mid' 作為目前的最佳答案
                right = mid - 1;   // 嘗試在左半邊 (更小速度) 尋找
            } else {
                // 如果當前速度 'mid' 無法在 h 小時內吃完 (太慢了)
                // 說明我們需要更快的速度。
                left = mid + 1;    // 在右半邊 (更大速度) 尋找
            }
        }
        return ans;
    }
};
