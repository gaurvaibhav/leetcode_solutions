class Solution
{
public:
    int flipgame(vector<int>& fronts, vector<int>& backs)
    {
        int n, i, res;
        n = fronts.size();
        res = INT_MAX;
        unordered_map<int, int> mp;
        for(i=0; i<n; ++i)
        {
            if(fronts[i] == backs[i])
            mp[fronts[i]]++;
        }
        for(i=0; i<n; ++i)
        {
            if(!mp.count(fronts[i]))
            {
                res = min(res, fronts[i]);
                mp[fronts[i]]++;
            }
            if(!mp.count(backs[i]))
            {
                res = min(res, backs[i]);
                mp[backs[i]]++;
            }
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};