#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution {
public:
    ll solve(ll n, vector<ll>& dp) {
        FASTIO;
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        ll res = solve(n - 1, dp) * (2 * n - 1) * n % MOD;
        return dp[n] = res;
    }
    int countOrders(int n) {
        FASTIO;
        vector<ll> dp(n+1, -1);
        return solve(n, dp);
    }
};