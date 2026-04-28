class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> tmp;

        for (auto &c : tokens) {
            if (c == "*" || c== "/" || c == "+" || c == "-") {
                int arg2 = tmp.top();
                tmp.pop();

                int arg1 = tmp.top();
                tmp.pop();

                if (c == "*") {
                    tmp.push(arg1 * arg2);
                } else if (c == "/") {
                    tmp.push(arg1 / arg2);
                } else if (c == "+") {
                    tmp.push(arg1 + arg2);
                } else if (c =="-") {
                    tmp.push(arg1 - arg2);
                }
            } else {
                tmp.push(stoi(c));
            }
        }

        return tmp.top();
    }
};
