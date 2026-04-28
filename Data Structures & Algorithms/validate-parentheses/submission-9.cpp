class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = { 
            {')', '('},
            {'}', '{'},
            {']', '['}
            };

        string st; // 用來當代替被關的左括號, 把string 當stack 用
        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if(mp.count(s[i])) {
                if (st.empty() || st.back() != mp[s[i]]) {
                    //假設當時左括號stack 為空 或是
                    // stack 最外面那個 不是map[c]的左括號
                    return false;
                }
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }

           

        
        }

         return st.size() == 0;
        
    }
};
