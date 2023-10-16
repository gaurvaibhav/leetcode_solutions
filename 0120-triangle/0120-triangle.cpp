#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
private:
    int solve(int i, int j, int n, vector<vector<int>>& arr, vector<vector<int>>& dp)
    {
        FASTIO;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int x, y;
        x = arr[i][j] + solve(i+1, j, n, arr, dp);
        y = arr[i][j] + solve(i+1, j+1, n, arr, dp);
        return dp[i][j] = min(x, y);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        FASTIO;
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, 0, n, triangle, dp);
    }
};