#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MOD 1000000007
#define pp pair<int, int>
#define vii vector<vector<int>>
#define vi vector<int>
#define pb push_back
class Solution
{
public:
    vi findDiagonalOrder(vii& a)
    {
        FASTIO;
        int n, i, j;
        n = a.size();
        queue<pp> q; vi res;
        q.push({0, 0});
        while(!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop(); res.pb(a[i][j]);
            if(j==0 && i+1 < n) q.push({i+1, 0});
            if(j+1 < a[i].size()) q.push({i, j+1});
        }
        return res;
    }
};