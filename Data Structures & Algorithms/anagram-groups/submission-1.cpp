class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> tbl;// sorted arr and original str
        vector<vector<string>> ans;

        for (auto &c: strs) {
            string tmp = c;
            sort(tmp.begin(), tmp.end());
            tbl[tmp].push_back(c);
        }

        for (auto & pair: tbl) {
            ans.push_back(move(pair.second));
        }

        return ans;
    }
};
