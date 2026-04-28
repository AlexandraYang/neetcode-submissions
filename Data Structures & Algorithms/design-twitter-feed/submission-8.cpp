class Twitter {
private:
    int time;
    //每個「追蹤者follower」對應到一個「他追蹤的人集合」
    unordered_map<int, unordered_set<int>> following; //key: followerId, value: followeeIds
    
    unordered_map<int, vector<pair<int, int>>> tweets; // key: userId, value: vector of {timeStamp, tweetId}
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

        priority_queue<pair<int, int>> pq;
        for (int user: candidates) {
            //假設貼文list有找到
            if (tweets.count(user)) {
                for (auto& tweet: tweets[user]) {
                    pq.push(tweet);
                }
            }
        }

        //重新找top 10
        vector<int> result;
        int cnt = 0;


        while(!pq.empty() && cnt < 10) {
            // 其實生成docygen 感覺沒問踢
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            // 不能追蹤自己
            return;
        }

        following[followerId].insert(followeeId); //following 是紀錄用戶 跟他的一群追隨者
    }
    
    // follower -> 主動按 follow 的那個人
    // followee -> 被別人 follow 的那個人
    void unfollow(int followerId, int followeeId) {
        //主動follow 別人的人假設發現自己follow的對象有來
        // 那就可以erase了
            if(following.count(followerId)) {
                following[followerId].erase(followeeId);
            }
    }
};
