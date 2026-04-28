class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tmp(nums.begin(), nums.end());
        int maxLength = 0;
        for (const  int& num: nums) {
            //假設num-1 不存在在tmp內，那代表num 是起點
            if (tmp.find(num-1) == tmp.end()) {
                //假設出現3 那找2就好 
                int currentLength = 1;
                int cur_num = num;
                while (tmp.find(cur_num+1) != tmp.end()) {
                    currentLength+=1;
                   cur_num += 1;
                }

                 maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
