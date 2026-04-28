class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars; // position , total_arr_time

        for (int i = 0; i < position.size(); ++i) {
            double total_arr_time = (double) (target-position[i])/speed[i];
            cars.push_back({position[i], total_arr_time});
        }

        sort(cars.begin(), cars.end());

        int fleet = 0;
        double last_car_arr_time = 0;
        for (int i = cars.size() -1 ; i >= 0; --i) {
            double cur_car_arr_time = cars[i].second;
            if (cur_car_arr_time > last_car_arr_time) {
                //假設我當前的車比我現在arr到的車時間更久
                //就代表我速度更慢
                fleet++;
                last_car_arr_time = cur_car_arr_time;
            }
        }

        return fleet;
    }
};
