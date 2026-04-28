class CountSquares {
public:
    map<pair<int, int>, int> cnt;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans= 0;

        for (auto& [p, c] : cnt) {
            int x1 = p.first;
            int y1 = p.second;

            //
            if(y != y1 || x == x1) {
                //假設不是水平線的話 !
                continue;
            }

            int d = abs(x1 - x);//正方形邊長

            ans += c * cnt[{x, y+d}] * cnt[{x1, y+d}];
            ans += c * cnt[{x, y-d}] * cnt[{x1, y-d}];
            
        }

        return ans;
    }
};
