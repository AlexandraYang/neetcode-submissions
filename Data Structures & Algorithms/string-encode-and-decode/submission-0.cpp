class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (const string& s :strs) {
            ans += to_string(s.size()) + "#" + s; 
            // {'home', 'loves', 'Dan'}會變成 4#home5#loves3#Dan 
            // 字數+ "#"
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector <string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++; //紀錄#所在的idx
            }

            int len = stoi(s.substr(i, j-i)); 
            // i 起始，j是 '#'的位子，j-1 會得到#的前一位 也就是數字長度，char 轉成int
            res.push_back(s.substr(j+1, len)); 
            // j+1 就是下一個字的第一個數字  ，substr 到它的長度

            i = j+1+len; // i 就是下一個 4#home  或是 3#Dan 這樣
        }

        return res;
    }
};
