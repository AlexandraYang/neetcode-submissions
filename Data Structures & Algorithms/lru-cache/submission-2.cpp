class LRUCache {

    /*
    list<pair<int, int>> lruList:

這個 list 用來存放所有的 key-value 配對（即每一個節點是 pair<int, int>）。

list 是雙向鏈表，可以高效地進行插入和刪除操作。特別是在 LRU Cache 中，當需要移動某個 key 到最前面或最末端時，list 能夠在 O(1) 的時間內完成這些操作。

unordered_map<int, list<pair<int, int>>::iterator> cache:

unordered_map 用來存儲 key 和對應的節點 迭代器。

這裡的迭代器指向 lruList 中的節點，這樣我們就能夠快速地查找某個 key 的 value 並對其進行更新，並且能夠在 lruList 中進行插入或刪除。


    */
private:
    int capacity;
    list<pair<int, int>> lruList; // key and value
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key and node in list's position

public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            // if key is not in cache
            return -1;
        }

        auto node = cache[key]; // get iter
        // node 是 list<pair<int, int>>::iterator

        int val = node->second;

        lruList.erase(node);
        lruList.push_front({key, val});
        cache[key] = lruList.begin();

        return val;

    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        }

        if (lruList.size() >= capacity) {
            auto last_node = lruList.back();
            cache.erase(last_node.first);
            lruList.pop_back();
        }

        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};
