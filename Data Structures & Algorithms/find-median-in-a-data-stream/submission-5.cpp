class MedianFinder {
private: 
    priority_queue<int> left; // max heap 
    priority_queue<int, vector<int>, greater<int>> right; //min heap 

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //step1: add val 
        left.push(num);

        //step 2: sequencea
        if (!right.empty() && left.top() > right.top()){
            int a = left.top(); left.pop();
            int b = right.top(); right.pop();
            left.push(b);
            right.push(a);
        }


        //step3: re-size 
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
            return right.size();
        } else {
            return (right.top()+left.top())/2.0;
        }
    }
};
