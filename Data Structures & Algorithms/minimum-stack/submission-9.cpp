class MinStack {
private:
     vector<int> minStk;
        vector<int> stk;
public:
/*
你現在這種寫法 = 每一層都有自己的 min
所以：
拿掉一層，就要把那一層的 min 一起拿掉
*/
    MinStack() {
       
    }
    
    void push(int val) {
        stk.push_back(val);
        
        if(minStk.empty()) {
            minStk.push_back(val);
        } else {
            minStk.push_back(min(val, minStk.back()));
        }
    }
    
    void pop() {

        minStk.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};
