#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MOD 1000000007
class Solution
{
private:
    vector<vector<int>> dp;
    int solve(int i, int j, int k)
    {
        if(i == j && k == 0) return 1;
        if(k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        return dp[i][k] = (solve(i+1, j, k-1) + solve(i-1, j, k-1)) % MOD;
    }
public:
    int numberOfWays(int i, int j, int k)
    {
        i += 2000;
        j += 2000;
        dp = vector<vector<int>> (4000, vector<int> (k+1, -1));
        return solve(i, j, k);
    }
};