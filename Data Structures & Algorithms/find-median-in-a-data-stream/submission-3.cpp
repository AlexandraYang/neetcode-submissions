class MedianFinder {
private: 
    priority_queue<int> left;//max heap 
    priority_queue<int, vector<int>, greater<int>> right;//min heap
public:
    MedianFinder() {}
    
    void addNum(int num) {
        //step1: send into left
        left.push(num);

        //step2: check size
        if (left.size() > right.size() +1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()+1) {
            left.push(right.top());
            right.pop();
        }

        // step3: check value
        if (!right.empty() && left.top() > right.top()) {
            int a = left.top(); left.pop();
            int b = right.top(); right.pop();
            left.push(b);
            right.push(a);
        }


    }
    
    double findMedian() {
        //step3: return median
        if (left.size() > right.size()) {
            return left.top();
        } else if (right.size() > left.size()) {
            return right.top();
        } else {
            return (right.top()+left.top())/2.0;
        }
    }
};
