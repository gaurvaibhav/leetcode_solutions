#define ll long long
#define MOD 1000000007
class Solution {
public:
    ll solve(ll n, vector<ll>& dp) {
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        ll res = solve(n - 1, dp) * (2 * n - 1) * n % MOD;
        return dp[n] = res;
    }
    int countOrders(int n) {
        vector<ll> dp(n+1, -1);
        return solve(n, dp);
    }
};