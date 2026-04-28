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
        struct Node {
            int time;
            int tweetId;
            int userId;
            int index;
        };

        auto cmp = [](Node& a, Node& b) {
            return a.time < b.time; //max heap
        };

        priority_queue<Node, vector<Node>, decltype(cmp) > pq(cmp); 
    
        unordered_set<int> candidates;
        candidates.insert(userId);

        if(following.count(userId)) {
            for (int followee: following[userId]) {
                candidates.insert(followee);
            }
        }

        // 2️⃣ 每個人只丟最新一篇
        for(int user: candidates) {
            //假設貼文結構 有找到這個user, 且這user發的文數目不為空
            if(tweets.count(user) && !tweets[user].empty()) {
                int lastIdx = tweets[user].size() -1;
                pq.push({
                    tweets[user][lastIdx].first,// 但 vector 本身是可以再索引的。
                    tweets[user][lastIdx].second,
                    user,
                    lastIdx
                });
            }
        }

        vector<int> result;

        while(!pq.empty() && result.size() < 10) {
            auto top = pq.top();
            pq.pop();

            result.push_back(top.tweetId);

            if(top.index > 0) {
                int newIndex = top.index -1;
                pq.push({
                    tweets[top.userId][newIndex].first,
                    tweets[top.userId][newIndex].second,
                    top.userId,
                    newIndex
                });
            }
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
