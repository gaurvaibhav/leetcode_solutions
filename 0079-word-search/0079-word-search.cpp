#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
private:
    vector<pair<int, int>> dir = 
    {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    vector<vector<bool>> vis;
    bool valid(int r, int c, int n, int m)
    {
        FASTIO;
        return (r>=0 && r<n && c>=0 && c<m);
    }
    bool dfs(int r, int c, int n, int m, int ind, int s, vector<vector<char>>& arr, string& str)
    {
        FASTIO;
        if(ind == s) return true;
        if(!valid(r, c, n, m) || vis[r][c] || str[ind] != arr[r][c]) return false;
        vis[r][c] = true;
        for(int i=0; i<4; ++i)
        {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            bool res = dfs(nr, nc, n, m, ind+1, s, arr, str);
            if(res) return true;
        }
        return vis[r][c] = false;
    }
public:
    bool exist(vector<vector<char>>& ar, string w)
    {
        FASTIO;
        int i, j, n, m, s;
        n = ar.size();
        m = ar[0].size();
        s = w.length();    
        vis = vector<vector<bool>> (n, vector<bool> (m, false));
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                if(ar[i][j] == w[0])
                {
                    if(dfs(i, j, n, m, 0, s, ar, w)) return true;
                }
            }
        }
        return false;
    }
};