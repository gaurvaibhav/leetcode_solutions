class Solution
{
private:
    vector<vector<int>> dp;
    int solve(int row, int col, int n, int m, vector<vector<int>>& arr)
    {
        if(row < 0 || row >= n || col < 0 || col >= m || !arr[row][col]) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int d, r, b;
        d = solve(row+1, col+1, n, m, arr);
        r = solve(row, col+1, n, m, arr);
        b = solve(row+1, col, n, m, arr);
        return dp[row][col] = (1 + min(d, min(r, b)));
    }
public:
    int countSquares(vector<vector<int>>& arr)
    {
        int n, m, i, j, res;
        n = arr.size();
        m = arr[0].size();
        res = 0;
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                if(arr[i][j]) res += solve(i, j, n, m, arr);
            }
        }
        return res;
    }
};