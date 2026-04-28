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
        unordered_set<int> candidates;
        candidates.insert(userId);

        if (following.count(userId)) {
            for (int followee: following[userId]) {
                candidates.insert(followee);
            }
        }

        priority_queue<pair<int,int>> pq;

        for (int user: candidates) {
            if (tweets.count(user)) {
                for (auto& tweet: tweets[user]) {
                    pq.push(tweet); // ← 整個 pair
                }
            }
        }

        vector<int> result;
        int cnt = 0;

        while(!pq.empty() && cnt < 10) {
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }

        return result;
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
