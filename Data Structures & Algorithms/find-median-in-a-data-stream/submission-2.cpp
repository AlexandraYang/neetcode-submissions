class MedianFinder {
private: 
    priority_queue<int> left; // max heap, top() 是大數字 
    priority_queue<int, vector<int>, greater<int>> right; // min heap, top() 是小數字

public:
    MedianFinder() {}      
    
    void addNum(int num) {
        // step 1: 先丟左heap 
        left.push(num);

        // step 2: 檢查順序 是否左數top() 有大於右樹的top() 
        if (!right.empty() && left.top() > right.top()) {
            int a = left.top(); left.pop();
            int b = right.top(); right.pop();
            left.push(b);
            right.push(a);
        }

        // step 3: 檢查size 是否正確 右邊heap size需要 小於左邊+1 ；左邊heap size也需要小於 右邊+1  
        if (right.size() > left.size() + 1) {
            //假設right min heap比較大 
            left.push(right.top());
            right.pop();
        } else if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        // 假設左邊size 大 則return left.top()
        //假設右邊size 大 則return right.top()
        //假設兩邊等長，則return (right.top() + left.top())/2.0 -> MUST double!! 

        if (left.size() > right.size()) {
            return left.top();
        } else if (right.size() > left.size()) {
            return right.top();
        } else {
            return (left.top() + right.top())/2.0;
        }
        
    }
};
