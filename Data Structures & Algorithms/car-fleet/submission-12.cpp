class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //space and timestamp
        vector<pair<int, double>> vp;

        // postition = time * speed
        // time = position/speed
        for (int i = 0; i < speed.size(); ++i) {
            double time = (double) (target - position[i])/speed[i];
            vp.push_back({position[i], time});
        }

        sort(vp.begin(), vp.end());
        int fleet = 0;
        double last_car_arr_time = 0;
        //從最靠近target的開始
        for (int i = vp.size() -1 ; i >= 0; --i) {
            double cur_car_time = vp[i].second; //OMG!!

            if (cur_car_time > last_car_arr_time) {
                //假設新的車到達時間比我更慢 那就是新增一個fleet
                // 且更新time
                fleet++;
                last_car_arr_time = cur_car_time;
            }
        }

        return fleet;
    }
};
