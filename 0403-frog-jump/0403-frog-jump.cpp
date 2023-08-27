#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    bool solve(int ind, int n, vector<int>& arr, int k, vector<vector<int>>& dp) {
        FASTIO;
        if(ind == n) {
            return true;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        bool ans = false;
        for(int i=ind+1; i<=n; i++) {
            if(arr[i] > (arr[ind]+k+1)) break;
            else if(arr[i] == arr[ind]+k-1) ans = ans||solve(i,n,arr,k-1,dp);
            else if(arr[i] == arr[ind]+k) ans = ans||solve(i,n,arr,k,dp);
            else if(arr[i] == arr[ind]+k+1) ans = ans||solve(i,n,arr,k+1,dp);
        } 
        return dp[ind][k] = ans;
    }
    bool canCross(vector<int>& stones) {
        FASTIO;
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(0,n-1,stones,0,dp);
    }
};