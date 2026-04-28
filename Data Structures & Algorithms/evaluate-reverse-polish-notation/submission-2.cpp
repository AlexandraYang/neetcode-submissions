class Solution {
private:
    int idx;
    int arr[10000];
    
    void pop() {
        if (idx > 0) {
            idx--;
        }
    }

    void push(int val) {
        arr[++idx] = val;
    }

    int top() {
        return arr[idx];
    }
public:
    int evalRPN(vector<string>& tokens) {
        
        idx = -1;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = top(); 
                pop();
                int a = top(); 
                pop();
                if (tokens[i] == "+") {
                    push(a+b);
                } else if (tokens[i] == "-") {
                    push(a-b);
                } else if (tokens[i] == "*") {
                    push(a*b);
                } else if (tokens[i] == "/") {
                    push(a/b);
                }
            } else {
                // if char -> int
                push(stoi(tokens[i]));
            }
            
        }

        return top();
    }
};
