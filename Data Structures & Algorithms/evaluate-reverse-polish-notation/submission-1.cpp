class Solution {
private:
    int idx = -1;
    double arr[10000];
public:
    int top() {
        return arr[idx];
    }

    void pop() {
        if (idx < 0) {
            return;
        }
        idx--;
    }

    void push(int val) {
        arr[++idx] = val;
    }


    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                push(stoi(tokens[i]) );
            } else {
                if (tokens[i] == "+") {
                    double num1 = top();
                    pop();

                    double num2 = top();
                    pop();

                    push(num1 + num2);
                }
                

                if (tokens[i] == "-") {
                    double num1 = top();
                    pop();

                    double num2 = top();
                    pop();

                    push(num2 - num1);
                }

                if (tokens[i] == "*") {
                    double num1 = top();
                    pop();

                    double num2 = top();
                    pop();

                    push(num2 * num1);
                }

                if (tokens[i] == "/") {
                    double num1 = top();
                    pop();

                    double num2 = top();
                    pop();

                    push(num2 / num1);
                }
            }
        }

        return (int) top();
    }
};
