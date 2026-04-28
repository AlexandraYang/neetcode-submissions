class Solution {
public:
    bool isValid(string s) {
        char arr[s.length()];
        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                arr[idx] = s[i];
                idx++;
            } else {    
                if (idx == 0) {
                    return false;
                }

                char tmp = arr[--idx];
                if ((s[i] == '}'&& tmp != '{') || 
                (s[i] == ']' && tmp != '[') ||
                (s[i] == ')' && tmp != '(') ) {
                    return false;
                }

            }
        }

        return idx == 0; // for single mark 檢查array 內是否還有東西


    }
};
