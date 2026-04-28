class CountSquares {
private:
    map<pair<int, int>, int> cnt; // {x, y} <--> freq
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;
        for (auto& [position, freq]: cnt) {
            int x1 = position.first;
            int y1 = position.second;
            //假設不是水平線的話
            // 必須在同一條水平線，且不是自己
            if (x1 == x || y1 != y) {
                continue;
            }

            int distant = abs(x - x1);
            // 正上方正方形
            ans += freq * cnt[{x, y+distant}] * cnt[{x1, y1+distant}];
            // 正下方正方形
            ans += freq * cnt[{x, y-distant}] * cnt[{x1, y1-distant}];
        }

        return ans;
    }
};
