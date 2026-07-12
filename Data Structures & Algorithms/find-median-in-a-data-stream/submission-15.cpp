class MedianFinder {
private: 
    priority_queue<int> left;//max heap 
    priority_queue<int, vector<int>, greater<int>> right; // min heap 

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //step1: add num into left 
        left.push(num);

        // step2: sequenece 
        //第一次就要能搬 
        if (!right.empty() && left.top() >right.top() ) {
            int a = left.top(); left.pop();
            int b = right.top(); right.pop();

            left.push(b);
            right.push(a);
        }

        //step3: 
        if (left.size() > right.size() +1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() +1) {
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
            return (left.top() + right.top())/2.0;
        }
    }
};
