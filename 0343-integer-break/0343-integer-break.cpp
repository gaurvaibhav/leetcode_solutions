#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution
{
private:
    int solve(int ind, int n, vector<vector<int>>& dp)
    {
        FASTIO;
        if(ind == 0 || n == 0) return 1;
        if(dp[n][ind] != -1) return dp[n][ind];
        if(ind > n) return dp[n][ind] = solve(ind-1, n, dp);
        return dp[n][ind] = max((ind * solve(ind, n-ind, dp)), solve(ind-1, n, dp));
    } 
public:
    int integerBreak(int n)
    {
        FASTIO;
        vector<vector<int>> dp(n+1, vector<int> (n, -1));
        return solve(n-1, n, dp);
    }   
};