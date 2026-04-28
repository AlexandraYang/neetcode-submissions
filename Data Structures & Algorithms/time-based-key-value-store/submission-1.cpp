class TimeMap {
public:

    unordered_map <string, vector<pair<int, string>>> m; // key --> {timeStamp, value}

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            // if not found
            return "";
        }

        const vector<pair<int, string>> & vec = m[key];
        int left = 0, right = vec.size() -1;
        string result = "";
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (vec[mid].first == timestamp) {
                return vec[mid].second; 
            } else if (vec[mid].first > timestamp) {
                // result = vec[mid].second; 
                right = mid -1;
            } else {
                result = vec[mid].second; // 你不一定能找到「剛好等於」的 timestamp。 但你要回傳「小於等於它的最大 timestamp 對應的 value」。
                left = mid +1;
            }
        }

        return result;
    }
};
