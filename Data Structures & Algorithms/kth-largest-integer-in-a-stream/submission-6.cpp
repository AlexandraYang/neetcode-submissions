class KthLargest {
private: 
    int limit_size;
    priority_queue<int, vector<int>, greater<int>> q;

public:
    KthLargest(int k, vector<int>& nums) {
        //return 第K個大的  那就需要由小到大 
        limit_size = k;
        
        for (int num: nums) {
            q.push(num);

            if (q.size() > k) {
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > limit_size) {
            q.pop();
        }
        
        return q.top();
    }
};
