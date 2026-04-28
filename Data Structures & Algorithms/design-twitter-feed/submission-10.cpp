class Twitter {
private:
    int time;
    //每個「追蹤者follower」對應到一個「他追蹤的人集合」
    //某個人 → 他追蹤的所有人
    unordered_map<int, unordered_set<int>> following; //key: 主動followerId, value: 被動followeeIds
    
    unordered_map<int, vector<pair<int, int>>> tweets; // key: userId, value: vector of {timeStamp, tweetId}
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        //紀錄user 跟他的發文，文用time + 
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> candidates;
        //把userId 先存入set, 因為後續要從following找到所有相關的
        candidates.insert(userId);

        //找到相關的使用者 且insert到該candidate 
        //也就是找到相關的人
        if (following.count(userId)) {
            for (int followee: following[userId]) {
                candidates.insert(followee);
            }
        }


        priority_queue<pair<int, int>> pq;
        for (int user: candidates) {
            //假設從貼文結構中 找出所有存在在candidate的用戶 且記錄他們的<timestamp , tweetId>
            if (tweets.count(user)) {
                for (auto& tweet: tweets[user]) {
                    //priority queue 會先排.first的，也就是timestamp越新的
                    pq.push(tweet);
                }
            }
        }

        //重新找top 10
        vector<int> result;
        int cnt = 0;

        while(!pq.empty() && cnt < 10) {
            //因為我用priority queue, default 是由大到小 
            //我就丟入tweetsID 進入答案的vector
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }

        return result;
    }
    
    //er主動，ee被動
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            // 不能追蹤自己
            return;
        }

        following[followerId].insert(followeeId); //following 是紀錄用戶 跟 "被他follow的人"
    }
    
    // follower -> 主動按 follow 的那個人
    // followee -> 被別人 follow 的那個人
    void unfollow(int followerId, int followeeId) {
        //主動follow 別人的人假設發現自己follow的對象有來
        // 那就可以erase了
        if(following.count(followerId)) {
            //本來主動加人的那個人 (follower) 把它自己的好友清單 (followee) 刪掉
            following[followerId].erase(followeeId);
        }
    }
};
