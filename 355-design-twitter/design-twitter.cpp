class Twitter {
    private:
    int timeStamp = 0;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> Tweets;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        Tweets[userId].push_back({timeStamp++, tweetId});
        
    }

    
    vector<int> getNewsFeed(int userId) {
  priority_queue<pair<int, int>> pq;

        // include own tweets
        for (auto& tweet : Tweets[userId]) {
            pq.push(tweet);
        }

        // include tweets from users userId follows
        for (int followeeId : followers[userId]) {
            for (auto& tweet : Tweets[followeeId]) {
                pq.push(tweet);
            }
        }

        // get top 10 tweets
        vector<int> res;
        int count = 0;
        while (!pq.empty() && count < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {

       if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
             followers[followerId].erase(followeeId);
        }
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */