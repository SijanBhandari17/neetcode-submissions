class Twitter {
   private:
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<pair<int,int>>> post;
    int timestamp = 0;

   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) { post[userId].push_back({timestamp++,tweetId}); }

    vector<int> getNewsFeed(int userId) {
        int k = 10;
        priority_queue<pair<int,int>> newsfeed;
        unordered_set<int> following = followList[userId];
        vector<int> feed;
        following.insert(userId);
        for (const int followee : following) {
            auto &temp = post[followee];
            int k = 10;
            for(int i = temp.size() -1 ; i >= 0 && k;i-- , k--){
                newsfeed.push(temp[i]);
  
            }
        }
        while (k && !newsfeed.empty()) {
            feed.push_back(newsfeed.top().second);
            newsfeed.pop();
            k--;
        }
        return feed;
    }

    void follow(int followerId, int followeeId) { 
        followList[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);

    }
};
