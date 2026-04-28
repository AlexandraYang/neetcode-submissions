class LRUCache {
public:
    int limited;
    list<pair<int, int>> lru_list;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    
    LRUCache(int capacity) {
        this->limited = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            //假設有找到key對應的iterator
            auto it = mp[key];
            int val = it->second;

            lru_list.erase(it);
            lru_list.push_front({key, val});

            mp[key] = lru_list.begin();
            return val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            //delete old iterator
            lru_list.erase(mp[key]);
        } else if (lru_list.size() >= limited) {
            //evict tail of list
            auto it = lru_list.back();
            mp.erase(it.first);
            lru_list.pop_back();
        }

        lru_list.push_front({key,value});
        mp[key] = lru_list.begin();
    }
};
