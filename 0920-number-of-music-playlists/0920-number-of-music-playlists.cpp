#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
typedef long long ll;
class Solution {
public:
    ll MOD = 1e9+7;
    ll solve(int ind, int g, int k, int n, vector<vector<ll>>& dp){ 
        op;op;op;op;
        if(!g) return (ind == n);
        if(dp[ind][g]!=-1) return dp[ind][g];
        ll res = 0;
        res = (res+((n-ind)*solve(ind+1,g-1,k,n,dp))%MOD)%MOD;
        if(ind >= k) 
            res = (res+((ind-k)*solve(ind,g-1,k,n,dp))%MOD)%MOD;
        return dp[ind][g] = res%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        op;op;op;op;
        vector<vector<ll>> dp(n+goal,vector<ll> (goal+1,-1));
        return solve(0,goal,k,n,dp);
    }
};

