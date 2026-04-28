class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <int, int> char_cnt;

        for (int i = 0; i < s.size(); ++i) {
            char_cnt[s[i]]++;
        }

        for (int j = 0; j < t.size(); ++j) {
            char_cnt[t[j]]--;
            if (char_cnt[t[j]] < 0) {
                return false;
            }
        }

        // 1. const: This means that within the loop, we cannot modify the element itself (the key or the value). 
        //           This is good practice when you only need to read the values.
        // 2. & (reference): This means that key and val will be references to the 
        //           actual key and value within the charCount map, rather than copies. 
        //           This is more efficient, especially for complex data types, and avoids unnecessary copying.
        for(auto const& [key, val]: char_cnt) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};
