class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        基本上這就是用數值 加演算法，檢查到是負數的話，就等於原來 val 已經對同一個 idx 做過運算了
        正負性作為訪問標記： 陣列中該索引位置的值的正負性被用作一個布林標記。

        正數： 表示這個索引（以及對應的原始數值）第一次被遇到。我們將其改為負數，標記為「已訪問」。
        負數： 表示這個索引（以及對應的原始數值）之前已經被遇到過。當我們再次遇到相同的數值並計算出相同的索引時，發現該位置已經是負數，這就證明了這個數值是重複的。
        */

        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) -1; //特殊演算法找出idx, 重複的數字出現的話會找出同一個idx
            if (nums[idx] > 0) {
                nums[idx] *= -1;
            } else {
                return abs(nums[i]);
            }
        }

        return -1; //拋出異常才走到這
    }
};
