class KthLargest {
private: 
    int limit_size;

    priority_queue<int, vector<int>, greater<int>> q;

public:
    KthLargest(int k, vector<int>& nums) {
        limit_size = k;

        for (int c: nums) {

            q.push(c);
            if (q.size() > limit_size) {
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
