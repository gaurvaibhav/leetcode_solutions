#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 12345
class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid)
    {
        FASTIO;
        ll p, ans;
        int n, m, i, j;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> pref(n, vector<int> (m));
        vector<vector<int>> suff(n, vector<int> (m));
        vector<vector<int>> res(n, vector<int> (m));
        p = 1;
        for(i=n-1; i>=0; --i)
        {
            for(j=m-1; j>=0; --j)
            {
                suff[i][j] = p;
                p *= grid[i][j];
                p %= MOD;
            }
        }
        p = 1;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                pref[i][j] = p;
                p *= grid[i][j];
                p %= MOD;
            }
        }
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                ans = pref[i][j] * suff[i][j];
                res[i][j] = ans % MOD;
            }
        }
        return res;
    }
};