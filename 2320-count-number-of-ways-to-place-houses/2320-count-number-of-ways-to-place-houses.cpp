#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MOD 1000000007
#define ll long long
class Solution {
private:
    int solve(int n, vector<ll>& dp) {
        op; 
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int take, notTake;
        take  = 1+solve(n-2, dp);
        notTake = solve(n-1, dp);
        return dp[n] = (take + notTake)%MOD;
    }
public:
    int countHousePlacements(int n) {
        op;
        vector<ll> dp(n+1,-1);
        ll res = solve(n, dp);
        res = ((2*res)+(res*res))%MOD;
        return (res+1)%MOD;
    }
};