class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following; //userId <--> 我follow人的清單
    unordered_map<int, vector<pair<int, int>>> tweets;//userId <---> {timestamp, tweesId}
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        struct Node {
            int time;
            int userId;
            int tweetId;
            int idx;
        };

        // 定義易錯 const 要加
        auto cmp = [](const Node& a, const Node &b) { 
            return a.time < b.time; 
        };

        //收集人員
        unordered_set<int> candidates;
        candidates.insert(userId);
        for (auto & c: following[userId]) {
            candidates.insert(c);
        }

        //收集人員的貼文
        // 定義Node
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

        for (auto & user: candidates) {
            
            if(tweets.count(user) && !tweets[user].empty()) {
                int idx = tweets[user].size() - 1;
                pq.push({
                    tweets[user][idx].first,
                    user,
                    tweets[user][idx].second,
                    idx
                });
            }
        }

        vector<int> res;
        while(!pq.empty() && res.size() < 10) {
            Node cur = pq.top(); // Node
            pq.pop();

            res.push_back(cur.tweetId); // 先把當前 tweet 加入答案

            if (cur.idx > 0) {          // ✅ 邊界檢查
                int newIdx = cur.idx - 1;

                // priority_queue 丟入下個
                pq.push({
                    tweets[cur.userId][newIdx].first,
                    cur.userId,
                    tweets[cur.userId][newIdx].second,
                    newIdx
                });
            }
            
            
        }

        return res;
    }

    
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        if (following[followerId].count(followeeId)) {
            following[followerId].erase(followeeId);
        }

    }
};
