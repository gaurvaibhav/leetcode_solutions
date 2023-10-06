#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
class Twitter
{
private:
    unordered_map<int, set<int>> following;
    unordered_map<int,  vector<pair<int, int>>> tweets;
    ll time;
public:
    Twitter()
    {
        time = 0;
        following = unordered_map<int, set<int>>();
        tweets = unordered_map<int,  vector<pair<int, int>>>();
    }

    void postTweet(int userId, int tweetId)
    {
        FASTIO;
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId)
    {
        FASTIO;
        priority_queue<pair<int, int>> pq;
        for(auto& it: tweets[userId])
        {
            pq.push(it);
        }
        for(auto& it: following[userId])
        {
            int u = it;
            for(auto& i: tweets[u])
            {
                pq.push(i);
            }
        }
        vector<int> res;
        while(!pq.empty() && res.size()<10)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId)
    {
        FASTIO;
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        FASTIO;
        following[followerId].erase(followeeId);
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