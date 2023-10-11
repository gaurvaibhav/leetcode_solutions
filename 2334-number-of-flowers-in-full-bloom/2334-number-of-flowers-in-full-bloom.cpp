class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)
    {
        vector<int> s, e, ans;
        for(auto& it: flowers)
        {
            s.push_back(it[0]);
            e.push_back(it[1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        for(int& person: people)
        {
            int x = upper_bound(s.begin(), s.end(), person) - s.begin();
            int y = lower_bound(e.begin(), e.end(), person) - e.begin();
            ans.push_back(x - y);
        }
        return ans;
    }
};