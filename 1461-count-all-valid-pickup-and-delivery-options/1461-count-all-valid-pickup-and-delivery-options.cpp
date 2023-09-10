#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution {
private:
    ll solve(ll p, ll d, vector<vector<int>>& dp) {
        FASTIO;
        if(p == 0 && d == 0) return 1;
        if(p<0 || d<0 || p>d) return 0;
        if(dp[p][d] != -1) return dp[p][d];
        ll p1 = p * solve(p-1, d, dp);
        ll p2 = (d-p) * solve(p, d-1, dp);
        return dp[p][d] = (p1+p2) % MOD;
    }
public:
    int countOrders(int n) {
        FASTIO;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(n, n, dp);
    }
};