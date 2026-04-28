class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string, vector<string>> map;//key: sorted, val: original str but it is vector!!
        for (const string &s: strs) {
            string key =s; // because sort() is a in-place , we must put it to a new arr
            sort(key.begin(), key.end()); 

            map[key].push_back(s);
        }

        for (auto& pair: map) {
            /*
            告訴 push_back：「嘿，你可以把 pair.second 當作一個即將被丟棄的東西（右值）來處理。」
            */
            ans.push_back(move(pair.second));
        }

        return ans;

    }
};
