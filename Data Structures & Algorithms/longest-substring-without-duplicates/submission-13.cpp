class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<int> count;
        int max_len = 0;


        for (int r = 0; r < s.size(); ++r) {

            while (count.find(s[r]) != count.end()) {
                count.erase(s[l]);
                l++;
            }

            count.insert(s[r]);
            max_len = max(max_len, r-l+1);
        }

        return max_len;
        
    }
};
