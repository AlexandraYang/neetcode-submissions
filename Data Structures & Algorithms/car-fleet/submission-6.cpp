class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars; //車的位置，到達終點的時間

        for (int i = 0; i < position.size(); ++i) {
            double time = (double) (target - position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        int fleets = 0;
        double lastTime = 0;
        for (int i = cars.size() -1; i >= 0; --i) {
            double time = cars[i].second;

            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};
