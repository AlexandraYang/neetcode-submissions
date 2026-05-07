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
        // 假設
        // 1 2 3{happy} 6{sad} 7
        if (mp.find(key) == mp.end()) {
            return "";
        }

        int l = 0;
        vector<pair<string, int>>& tmp = mp[key];
        int r = tmp.size() ;

        while (l < r) {
            int mid = l + (r-l)/2;

            if (tmp[mid].second <= timestamp) {
                l = mid + 1;
            } else {
                r = mid ;
            }
        }

        int idx = l -1;
        if (idx < 0) {
            return "";
        }

        return tmp[idx].first;
    }
};
