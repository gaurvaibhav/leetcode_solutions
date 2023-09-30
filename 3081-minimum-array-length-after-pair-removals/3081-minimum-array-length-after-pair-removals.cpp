class Solution
{
public:
    int minLengthAfterRemovals(vector<int>& nums)
    {
        int res;
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        res = 0;
        for(auto& num: nums)
        {
            mp[num]++;
        }
        for(auto& it: mp)
        {
            pq.push({it.second, it.first});
        }
        while(pq.size() > 1)
        {
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();
            it1.first--;
            it2.first--;
            if(it1.first)
            {
                pq.push(it1);
            }
            if(it2.first)
            {
                pq.push(it2);
            }
        } 
        while(!pq.empty())
        {
            res = pq.top().first;
            pq.pop();
        }
        return res;
    }
};