#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MOD 1000000007
class Solution
{
private:
    vector<vector<int>> dp;
    int solve(int ind, int k, int n)
    {
        FASTIO;
        if(k == 0 && ind == 0) return 1;
        if(ind < 0 || ind >= n || k == 0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        return dp[ind][k] = (((solve(ind+1, k-1, n)) % MOD + (solve(ind-1, k-1, n))) % MOD + (solve(ind, k-1, n)))% MOD;
    }
public:
    int numWays(int k, int n)
    {
        FASTIO;
        dp = vector<vector<int>> (k+1, vector<int> (k+1, -1));
        return solve(0, k, n);
    }
};