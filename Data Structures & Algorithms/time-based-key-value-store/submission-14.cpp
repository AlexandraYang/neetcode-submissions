class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp; //key <-> vector ->pair <val ; timestamp> 
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            // nothing
            return "";
        }
        
        vector<pair<int, string>> vec_buf = mp[key];
        int l = 0;
        int r = vec_buf.size();
        while(l < r) {
            int mid = l + (r-l)/2;
            // 1 3 4 6 6 7 8
            if (vec_buf[mid].first <= timestamp) {
                // floor 
                l = mid +1;
            } else {
                r = mid ;
            }
        }  

        int idx = l -1;
        if (idx < 0) {
            return "";
        }      

        return vec_buf[idx].second;

    }
};
