class MinStack {
private:
    const static int NUM_MAX = 10000;
    int arr[NUM_MAX];
    int minArr[NUM_MAX];
    int minIdx;
    int idx;
    
public:
    MinStack() {
        minIdx = -1;
        idx = -1;
    }
    
    void push(int val) {
        arr[++idx] = val;
        if (minIdx == -1 || val <= minArr[minIdx]) { // 想想假設兩個 -2的case!!
            minArr[++minIdx] = val;
        }
    }
    
    void pop() {
        if (idx < 0) {
            return;
        }

        int val = arr[idx--];
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
