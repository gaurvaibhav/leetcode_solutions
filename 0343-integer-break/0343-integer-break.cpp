#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
private:
    vector<vector<int>> dp;
    int solve(int ind, int n)
    {
        FASTIO;
        if(ind == 0 || n == 0) return 1;
        if(dp[n][ind] != -1) return dp[n][ind];
        if(ind > n) return dp[n][ind] = solve(ind-1, n);
        return dp[n][ind] = max((ind * solve(ind, n-ind)), solve(ind-1, n));
    } 
public:
    int integerBreak(int n)
    {
        FASTIO;
        dp = vector<vector<int>>(n+1, vector<int> (n, -1));
        return solve(n-1, n);
    }   
};