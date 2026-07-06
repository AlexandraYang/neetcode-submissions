class MedianFinder {
private: 
    priority_queue<int> left; // max heap, top() 必為最大
    priority_queue<int, vector<int>, greater<int>> right; // min heap, top() 最小
public:
    MedianFinder() {}
    
    // 1 2 3 7 8
    // 8 7 3 2 1
    void addNum(int num) {
        //step1: through it to left
        left.push(num);

        //step2: Make sure sequence is correct 
        //如果左邊top 比右邊最小的更大 
        if (!right.empty() && left.top() > right.top()) {
            int a = left.top(); left.pop(); //把大數拿出來 
            int b = right.top(); right.pop(); //把min heap的top() 最小的也拿出來 
            left.push(b); //先把小數丟入 max heap 
            right.push(a); //把大數入 min heap 
        }

        // step 3: balance size 
        if (left.size() > right.size() +1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() +1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {

        if (left.size() > right.size()) {
            return left.top();
        } else if (right.size() > left.size()) {
            return right.top();
        } else {
            return (right.top() + left.top()) /2.0;
        }
        
    }
};
