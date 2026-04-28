class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector <int> result (num1.size() + num2.size(), 0);

        for (int i = num1.size() -1 ; i >= 0; --i) {
            for (int j = num2.size() -1; j >= 0; --j) {
                int mul = (num1[i]-'0') * (num2[j] -'0');
                int sum = result[i + j + 1] + mul;

                result[i+j+1] = sum %10; //留著
                result[i+j] += sum / 10; //往左丟

            }
        }

        bool isStart = false;
        string ans;
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] != 0) {
                isStart = true;
            }

            if(isStart) {
                ans.push_back(result[i] + '0');
            }
        }

        return ans;
    }
};
