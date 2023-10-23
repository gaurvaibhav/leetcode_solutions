class Solution
{
private:
    vector<vector<int>> dp;
    int solve(int i, int j, int n, int m, vector<vector<char>>& arr)
    {
        if(i<0 || j<0 || i>=n || j>=m || arr[i][j] == '0')
        return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + min(solve(i+1, j+1, n, m, arr), min(solve(i+1, j, n, m, arr), solve(i, j+1, n, m, arr)));
    }
public:
    int maximalSquare(vector<vector<char>>& arr)
    {
        int i, j, n, m, res;
        n = arr.size();
        m = arr[0].size();
        if(n == 0) return 0;
        res = 0;
        dp = vector<vector<int>> (n, vector<int> (m, -1));
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                if(arr[i][j] == '1')
                {
                    res = max(res, solve(i, j, n, m, arr));
                }
            }
        }
        return res*res;
    }
};