class Solution
{
private:
    int solve(vector<int>& arr1, vector<int>& arr2, int ind, int n,vector<vector<int>>& dp)
    {
        if(n <= 0) return 0;
        if(ind >= arr1.size()) return 1e9;
        if(dp[ind][n] != -1) return dp[ind][n];
        int np, p;
        np = solve(arr1, arr2, ind+1, n, dp);
        p = arr1[ind] + solve(arr1, arr2, ind+1, n-arr2[ind]-1, dp);
        return dp[ind][n] = min(np, p);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        int n;
        n = cost.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(cost, time, 0, n, dp);
    }
};