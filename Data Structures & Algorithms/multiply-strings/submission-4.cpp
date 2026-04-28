class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }


        vector<int> res(num1.size() + num2.size(), 0);
        for (int i = num1.size() -1; i >= 0; --i) {
            for (int j = num2.size()-1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i+j+1];

                res[i+j] += sum / 10;
                res[i+j+1] = sum % 10;
            }
        }

        string ans; 
        bool isStart = false;
        for (int k =0; k < res.size(); ++k) {

           if (res[k] != 0) {
            isStart = true;
           }

            if (isStart) {
                ans.push_back(res[k] + '0');
            }
        }

        return ans;
    }
};






