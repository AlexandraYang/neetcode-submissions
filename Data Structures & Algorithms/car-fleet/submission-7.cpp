class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars; //車的起始位置，到達終點的時間

        for (int i = 0; i < position.size(); ++i) {
            double time = (double) (target - position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end()); // 幫我由小到大去排 所以前面反而離終點更遠

        int fleets = 0;
        double lastTime = 0;
        //但我們是反著來 由越靠近終點的先計算
        for (int i = cars.size() -1; i >= 0; --i) {
            double time = cars[i].second;


            // time 是我這台車 到終點的時間；
            // lastTime 是前面車隊 到終點的時間 
            // 如果我比前面那團還慢 → 我自己一團；否則我會撞上它
            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};
