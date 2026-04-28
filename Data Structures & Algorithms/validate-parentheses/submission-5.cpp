class Solution {
public:
    bool isValid(string s) {
        char arr [1024];
        int idx = -1;
        for (int i =0; s[i]; i++) {
            if ( (s[i] == '[') || (s[i] == '{') || (s[i] == '(')) {
                arr[++idx] = s[i];
            } else {
                if (idx < 0) {
                    return false;
                }

                char tmp = arr[idx--];
                if ( ((tmp == '[') && (s[i] != ']')) || 
                    ((tmp == '{') && (s[i] != '}')) || 
                    ((tmp == '(') && (s[i] != ')')) ) 
                    {
                    return false;
                }
            
            }
        }

        return idx == -1;
    }
};
