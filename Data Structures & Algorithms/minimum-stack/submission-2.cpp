class MinStack {
private:
    static const int MAX_SIZE = 10000;
    int arr[MAX_SIZE];
    int minArr[MAX_SIZE];
    int idx;     // 主棧頂索引
    int minIdx;  // min棧頂索引
    
public:
    MinStack() {
        idx = -1;
        minIdx = -1;
    }
    
    void push(int val) {
        arr[++idx] = val;
        
        if (minIdx == -1 || val <= minArr[minIdx]) {
            minArr[++minIdx] = val;
        }
    }
    
    void pop() {
        if (idx == -1) {
            //到底了
            return;
        }

        int val = arr[idx--]; //先取值才idx --
        if (val == minArr[minIdx]) {
            minIdx--;
        }
    }
    
    int top() {
        return arr[idx];
    }
    
    int getMin() {
        return minArr[minIdx];
    }
};
