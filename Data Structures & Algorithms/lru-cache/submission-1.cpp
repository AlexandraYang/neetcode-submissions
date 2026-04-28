class LRUCache {
    int capacity;
    list<pair<int, int>> lruList; // key: value
    unordered_map<int, list<pair<int, int>>::iterator  > cache; //key 和cache內的迭代器

public:
    LRUCache(int size) {
        capacity = size;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            //假設找不到
            return -1;
        }

        //假設找的到
        auto node = cache[key];
        int val = node->second;

        lruList.erase(node);
        lruList.push_front({key, val}); // 因為是最近被使用 所以放到front去
        cache[key] = lruList.begin();

        return val;
    }
    
    void put(int key, int value) {
        // 如果 key 存在，先移除原本的位置
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        }

        //如果超過容量，移除最舊的（list 最後面）
        if (lruList.size() >= capacity) {
            auto last = lruList.back();
            cache.erase(last.first);
            lruList.pop_back();
        }

        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};
