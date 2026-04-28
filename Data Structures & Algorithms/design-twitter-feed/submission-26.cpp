class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following; // user <--> {我追蹤的人}
    unordered_map<int, vector<pair<int, int>>> tweets; // userId <--> vector<pair<Timestamp, tweets>>
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
       
       vector<pair<int, int>> allTweets;

        // 因為vector 有override ，用法需要
        // insert(iterator pos, iterator first, iterator last);
       allTweets.insert(allTweets.end(),
                        tweets[userId].begin(),
                        tweets[userId].end()
       );

        for (int followee : following[userId]) {
            allTweets.insert(allTweets.end(),
                     tweets[followee].begin(),
                     tweets[followee].end());
        }
        // sort, timestamp 大的徘前面
       sort(allTweets.begin(), allTweets.end(),
        [](auto &a, auto&b) {
            return a.first > b.first;
        });
        
        //取前十個
        vector<int> result;
        for(int i = 0; i < min(10, (int)allTweets.size()); ++i) {
            result.push_back(allTweets[i].second);
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
