class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> tmp (nums.begin(), nums.end());

        int max_len = 0;
        for (int num : tmp) {
            if (tmp.find(num - 1) == tmp.end()) {
                // num is the beginning 

                int cur_num = num;
                int cur_len = 1;

                //    num_set.find(currentNum + 1) != num_set.end() 表示找到了 currentNum + 1
                while (tmp.find(cur_num+1) != tmp.end()) {
                    cur_len += 1;
                    cur_num +=1; //往下移一個
                }

                max_len = max(cur_len, max_len);
            }
        }

        return max_len;
    }
};
