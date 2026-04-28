class Solution {
private:
    int digit(int n) {
        int sum = 0;
        while(n > 0) {
            int d = n % 10;
            sum += d*d;
            n = n /10;
        } 
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set <int> record;
        while (n != 1) {
            if(record.count(n)) {
                //假設出現過
                return false;
            }
            record.insert(n);
            n = digit(n);
        }
        return true;
    }
};
