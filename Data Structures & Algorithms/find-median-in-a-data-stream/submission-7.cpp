class MedianFinder {
private: 
    priority_queue<int> left ; // max heap, 由小到大 
    priority_queue<int, vector<int>, greater<int>> right; // min heap 由大到小  
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //step1: Add 
        left.push(num);

        //step2: check sequence 
        //2. Fix Order SWAP 
        // max(left) <= min(right)
        if (!right.empty() && left.top() > right.top()) {


            int a = left.top(); left.pop();
            int b = right.top(); right.pop();
            
            left.push(b);
            right.push(a);
        }

        //step3: balance size ，|L-R| <= 1 
        if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        } else if (left.size() > right.size() +1) {
            right.push(left.top());
            left.pop();
        }

       

    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        } else if (right.size() > left.size()) {
            return right.top();
        } else {
            return (right.top() + left.top())/2.0;
        }
    }
};
