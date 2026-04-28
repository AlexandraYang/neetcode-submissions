class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // step 0
        // s is empty?

        // step 1:
        // left, right ptr 
        // define
        //      left ptr = 0
        //      unordered_map<char, int> mp;// key char, val is last idx
        // right ptr for loop string , 
        // if (mp[s[i]] >= left)
        //      left = mp[s[i]] + 1
        // mp[s[i]] = i

        // return r -l +1
        if (s.empty()) {
            return 0;
        } 

        unordered_map<char, int> mp;
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (mp.count(s[right]) && mp[s[right]]>= left) {
                left = mp[s[right]] + 1;
            }

            mp[s[right]] = right;
            max_len = max(max_len, right-left+1);
        }

        return max_len;

    }
};
