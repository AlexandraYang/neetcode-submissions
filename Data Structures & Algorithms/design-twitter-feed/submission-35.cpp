class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following; //userId <---> 跟他所有追蹤的人
    unordered_map<int, vector<pair<int, int>>> tweets;

    struct Node{
        int timestamp;
        int tweetId;
        int userId;
        int idx;
    };
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](Node &a, Node & b) {
            return a.timestamp < b.timestamp;
        };

        // priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmq);
        priority_queue<Node, vector<Node>, decltype(cmp) > pq(cmp);
        
        // Collect all candidate
        unordered_set <int> candidates;
        candidates.insert(userId);
        if(following.count(userId)) {
            for (auto &c: following[userId]) {
                candidates.insert(c);
            }
        }

        //每個人只丟一筆 且heap 的大小是 size_of_user
        for (int user: candidates) {
            if(tweets.count(user) && !tweets[user].empty()) {
                int lastIdx = tweets[user].size() -1; 
                pq.push({tweets[user][lastIdx].first, tweets[user][lastIdx].second, user, lastIdx}); // priority queue 沒有push_back
            }
        }
        

        vector<int> result;
        while(!pq.empty() && result.size() < 10) {
            auto top = pq.top();
            pq.pop();

            result.push_back(top.tweetId);

            if(top.idx > 0) {
                int newIdx = top.idx - 1;
                pq.push({ 
                    tweets[top.userId][newIdx].first,
                    tweets[top.userId][newIdx].second,
                    top.userId,
                    newIdx
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
         following[followerId].erase(followeeId);
    }
};
