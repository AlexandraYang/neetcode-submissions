class Solution {
private:
    // 拆digit
    int digit(int src) {
        int sum = 0;
        while(src > 0) {
            int last_digit = src % 10;
            sum += last_digit * last_digit; //要記得累加

            src = src / 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> record;
        while(n != 1) {
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
