class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        int left = 0;
        unordered_map<char, int> mp;
        int len_max = 0;

        for (int right = 0; right < n; right++) {
            char c =  s[right];
            mp[c]++;

            while (mp.size() > 2) {
                char leftChar = s[left];
                mp[leftChar]--;
                if (mp[leftChar] == 0) {
                    mp.erase(leftChar);
                }
                left ++;
            }
            len_max = max(len_max, right-left+1);

        }

        return len_max;
    }
};