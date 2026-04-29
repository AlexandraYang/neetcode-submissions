class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }
        vector<pair<int, string>>  vec_buf = mp[key];

        int l = 0;
        int r = vec_buf.size() ;
        while (l < r) {
            int mid = l + (r-l)/2;
            //此題upper bound 但-1 
            // 1 3 4 5 5 6 7, target = 6

            if (vec_buf[mid].first <=  timestamp) {
                l = mid +1;
            } else {
                r = mid;
            }
        }

        int idx = l - 1;
        if (idx < 0) {
            return "";
        }

        return vec_buf[idx].second;
    }
};
