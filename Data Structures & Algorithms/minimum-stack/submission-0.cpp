class MinStack {
private:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data_stack.push(val);
        if (min_stack.empty()) {
            min_stack.push(val);
        } else {
            int tmp = min_stack.top();
            min_stack.push(min(val, tmp));
        }

    }
    
    void pop() {
        data_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
