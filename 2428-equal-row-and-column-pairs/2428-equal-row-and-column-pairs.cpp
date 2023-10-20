class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        int res, n, i, j;
        res = 0;
        n = grid.size();
        map<vector<int>, int> mp;
        for(i=0; i<n; ++i)
        {
            mp[grid[i]]++;
        }
        for(i=0; i<n; ++i)
        {
            vector<int> col;
            for(j=0; j<n; ++j)
            {
                col.push_back(grid[j][i]);
            }
            res += mp[col];
        }
        return res;
    }
};