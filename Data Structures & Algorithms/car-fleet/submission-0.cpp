class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair<int, int>> record;
        for (int i =0 ; i < speed.size(); ++i) {
            record.push_back({position[i], speed[i]});
        }

        //跟預設從小到大不一樣，我們要從大到小 (從靠近終點的開始排)
        sort(record.rbegin(), record.rend()); 

        vector<double> stk;
        for (int i = 0; i < record.size(); ++i) {
            stk.push_back((double) (target - record[i].first)/record[i].second);

            if (stk.size() >= 2 && stk.back() <= stk[stk.size() - 2 ]) {
                stk.pop_back();
            }
        }

        return stk.size();
    }
};
