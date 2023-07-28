#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    bool solve(int ind, int n, vector<int>& arr,vector<int>& dp){
        op;
        if(ind >= n) return true;
        if(dp[ind] != -1) return dp[ind];
        bool ans = false;
        for(int i=1; i<=arr[ind]; i++) {
            ans = solve(ind+i,n,arr,dp);
            if(ans) break;
        }
        return dp[ind] = ans;
    }
    bool canJump(vector<int>& nums) {
        op;
        vector<int> dp(nums.size(),-1);
        return solve(0,nums.size()-1,nums,dp);
    }
};