class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;

        for (auto c: s) {
            switch (c) {
                case '[':
                case '(':
                case '{':
                    tmp.push(c);
                    break;
                case ']':
                    if (tmp.empty() || tmp.top() != '[') {
                        return false;
                    }
                    tmp.pop();
                    break;
                case ')':
                    if (tmp.empty() || tmp.top() != '(') {
                        return false;
                    }

                    tmp.pop();
                    break;
                case '}':
                    if (tmp.empty() || tmp.top() != '{') {
                        return false;
                    }
                    tmp.pop();
                    break;

                default:
                    break;    
            }
        }

        return tmp.size() == 0? true : false;
    }
};
