class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,deque<pair<int,int>>> post_data;
    unordered_map<int,unordered_set<int>> follow_data;
    int count;
    Twitter() {
        count = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post_data[userId].push_front(make_pair((count++),tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {

        vector<pair<int,int>> t_res;
        if (post_data.find(userId)!=post_data.end())
        {
            for (auto p:post_data[userId])
            {
                t_res.push_back(p);
                // push_heap(t_res.begin(), t_res.end());
                // if (t_res.size()>=10) break;
            }
        }
        if (follow_data.find(userId)!=follow_data.end())
        {
            for (auto it: follow_data[userId])
            {
                if (post_data.find(it)!=post_data.end())
                {
                    for (auto p:post_data[it])
                    {
                        // if (t_res.size()>=10 and p.first>(t_res.back()).first) break;
                        t_res.push_back(p);
                        // push_heap(t_res.begin(), t_res.end());
                        // if (t_res.size()>10) 
                        // {
                            // pop_heap(t_res.begin(),t_res.end());
                            // t_res.pop_back();
                        // }
                    }
                }
            }
        }
        // make_heap()
        
        vector<int> res;
        make_heap(t_res.begin(),t_res.end());
        for(int i=0;i<10;i++)
        {
            if (t_res.size()==0) break;
            pop_heap(t_res.begin(),t_res.end());
            res.push_back(t_res.back().second);
            t_res.pop_back();
        }
        // for (auto t:t_res) res.push_back(t.second);
        return(res);
        
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follow_data[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follow_data[followerId].erase(followeeId);
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