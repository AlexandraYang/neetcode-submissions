class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following; // user <--> {我追蹤的人}
    unordered_map<int, vector<pair<int, int>>> tweets; // userId <--> vector<pair<Timestamp, tweets>>

    struct Node {
        int timestamp;
        int tweetId;
        int userId;
        int index;
    };

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        /*
        步驟：
        建立 candidates（包含自己 + 所有 followee）
        把所有人的 tweet 全部收集起來
        排序（依 timestamp 由大到小）
        取前 10 個
        */
       
    
        //找出所有人
        unordered_set<int> allUser;
        allUser.insert(userId);
        for (auto & c: following[userId]) {
            allUser.insert(c);
        }


        auto cmp = [](const Node &a, const Node &b) {
            return a.timestamp < b.timestamp;
        };

        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

        for (int u : allUser) {
            if(!tweets[u].empty()) {
                int idx = tweets[u].size() -1;
                pq.push({tweets[u][idx].first, //timeStamp
                    tweets[u][idx].second, // userId
                    u, 
                    idx});
            }
        }
       

     
        
        //取前十個
        vector<int> result;
        while(!pq.empty() && result.size() < 10) {
            Node cur = pq.top();
            pq.pop();

            result.push_back(cur.tweetId);

            if (cur.index > 0) {
                int newId = cur.index - 1;
                pq.push({tweets[cur.userId][newId].first,
                    tweets[cur.userId][newId].second,
                    cur.userId,
                    newId
                });
            }
        }

        return result;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following[followerId].count(followeeId)) {
            following[followerId].erase(followeeId);
        }
    }
};
