class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        unordered_map <int, int> mp; // key-val, diff <-> idx 
        for (int i = 0; i < numbers.size(); ++i) {
            int diff = target - numbers[i]; 

            //假設我沒有找到diff, 我就先記錄我自己的idx
            if (mp.find(diff) == mp.end()) {
                mp[numbers[i]] = i; //輸入數值 就可以找到我的idx 
            } else{
                //假設有找到的話 
                ans.push_back( mp[diff] + 1);
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};
