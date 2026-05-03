class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});

    }
    
    string get(string key, int timestamp) {
        
        if (mp.find(key) == mp.end()) {
            return "";
        }

       
        
        vector<pair<string, int>> vec_buf = mp[key]; 
        int l = 0;
        int r = vec_buf.size();
        // floor  [l, r)
        while (l < r) {
            int mid = l + (r-l)/2;
            // 1 4 5 6
            //get(4) = 1's val 
            if (vec_buf[mid].second <= timestamp) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int idx = l -1;
        if (idx < 0) {
            return "";
        }

        return vec_buf[idx].first;
    }
};
