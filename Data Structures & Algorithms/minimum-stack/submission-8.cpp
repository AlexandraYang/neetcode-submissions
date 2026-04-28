class MinStack {
private:
    static const int MY_INT_MAX = 10000;
    int min_idx;
    int idx;
    int arr[MY_INT_MAX];
    int min_arr[MY_INT_MAX];
public:
    MinStack() {
        idx = -1;
        min_idx = -1;
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
