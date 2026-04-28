class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

       
        for (int i = 0; i< nums.size(); ++i) {
             //自己也要記得跳過
             if (i > 0 && nums[i] == nums[ i - 1]) //自己也要記得跳過
             {
                continue;
             }

             int left = i + 1; //這裡也忘記!!! add 1 是為了不要跟i打架
            int right = nums.size() - 1;
            while (left < right) {
                int tmp = nums[i] + nums[left] + nums[right];

                //!!!!! IMPORTANT!!!!!
                /*
                 我們將 0 當作基準，
                 透過比較當前三數總和與 0 的大小關係，來決定是要增加還是減
                
                */
                if (tmp > 0) {
                    --right;
                } else if (tmp < 0) {
                    ++left;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left+1]) {
                        ++left;
                    }

                    while (left < right && nums[right] == nums[right -1]) {
                        --right;
                    }

                    ++left;
                    --right;
                }

            }
        }
        return ans;
    }
    
};
