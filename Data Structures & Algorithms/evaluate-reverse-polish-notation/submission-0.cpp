class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long > record;
        /*
        原因：在 C++ 中，你不能直接將一個 std::string 對象
        （你的變量 c 就是這個類型，因為 tokens 是 vector<string>）
        與一個 char 字面量（例如 '+'）進行比較。
        你需要將 char 字面量也變成字符串字面量。
        */
        for (auto & c: tokens) {
            if (c == "+" || c =="-" || c == "*" || c == "/") {
                long long op2 = record.top();
                record.pop();

                long long op1 = record.top();
                record.pop();

                if (c == "+") {
                    int tmp = op1 + op2;
                    record.push(tmp);
                } else if (c == "-") {
                    int tmp = op1 - op2;
                    record.push(tmp);
                } else if (c == "*") {
                    int tmp = op1 * op2;
                    record.push(tmp);
                } else if (c == "/") {
                    int tmp = op1 / op2;
                    record.push(tmp);
                }
            } else {
                record.push(stoll(c)); // stoll string to long long
            }
        }

        return (int)record.top();
    }
};
