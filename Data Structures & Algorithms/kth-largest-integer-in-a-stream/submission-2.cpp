class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push(nums[i]);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }    
    }
    
    int add(int val) {  
        // 如果堆還沒滿 k 個元素，一定要 push
        if (minHeap.size() < k) {
            minHeap.push(val);
        }
        // 堆已滿，才用你的邏輯
        else if (minHeap.top() < val) {
            minHeap.push(val);
            minHeap.pop();
        }
        // 如果 val <= minHeap.top()，就不做事（保留 top）
        
        return minHeap.top();
    }
};
