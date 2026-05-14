class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;//用來記錄 idx  , 紀錄候選人的idx 
        vector<int> ans; // 用來記錄數值

        for (int r = 0; r < nums.size(); ++r) {
            //假設 新掃到的數值 比我候選人還要大 , 我候選人直接掰 
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            //紀錄idx到dq 去
            dq.push_back(r);

            // 因為上面插入以後 我要檢查是否超過我window的寬度了 
            // 當前 window 中「最左邊（最早進來）」的 index, 
            // 它不只是“最舊”，而是“目前候選最大值中最舊的那個”
            if (!dq.empty() && dq.front() < r - k +1 ) {
                //因為我從屁股插入, 所以舊的必然在front 要pop也是pop front
                dq.pop_front(); 
            }


            //確保windows 已經滿K個 
            /*
            -1 從哪來？

來自這個公式：

window 左邊界 = r - k + 1

整理：

window 範圍：
[r - k + 1, r]
當 r = k - 1：
左邊界 = 0
            
            
            */
            if ( r >= k -1) {
                ans.push_back(nums[dq.front()]);
            }

        }

        return ans;
    }
};
