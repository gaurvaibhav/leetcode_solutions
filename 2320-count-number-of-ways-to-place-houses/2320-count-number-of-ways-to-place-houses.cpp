#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define MOD 1000000007
#define ll long long
class Solution {
public:
    int countHousePlacements(int n) {
        op;
        vector<ll> dp(n+1,0);
        dp[1]=1;
        for(int i=2; i<=n; ++i) {
            int take, notTake;
            take  = 1+dp[i-2];
            notTake = dp[i-1];
            dp[i] = (take + notTake)%MOD;
        }
        ll res = dp[n];
        res = ((2*res)+(res*res))%MOD;
        return (res+1)%MOD;
    }
};