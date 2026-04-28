class MinStack {
private:
    int min_idx;
    int idx;
    static const int MAX_LEN = 10000;
    int arr[MAX_LEN];
    int min_arr[MAX_LEN];

public:
    MinStack() {
        min_idx = -1;
        idx = -1;    
    }
    
    void push(int val) {
        arr[++idx] = val;
        if (min_idx == -1 || val <= min_arr[min_idx]) {
            min_arr[++min_idx] = val;
        }
    }
    
    void pop() {
        if (idx < 0) {
            return;
        }

        int val = arr[idx--];
        if (val == min_arr[min_idx]) {
            min_idx--;
        }
    }
    
    int top() {
        return arr[idx];
    }
    
    int getMin() {
        return min_arr[min_idx];
    }
};
