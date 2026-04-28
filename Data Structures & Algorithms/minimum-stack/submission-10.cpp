class MinStack {
private:
    vector<int> stk;
    vector<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);

        if (minStk.empty()) {
            minStk.push_back(val);
        } else {
            minStk.push_back(min(minStk.back(), val));
        }
        
    }
    
    void pop() {
        stk.pop_back();
        minStk.pop_back();
        
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};
