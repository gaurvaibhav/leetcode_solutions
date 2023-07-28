class Solution {
public:
    bool solve(int ind, int n, vector<int>& arr,vector<int>& dp){
        if(ind >= n) return true;
        if(dp[ind] != -1) return dp[ind];
        bool ans = false;
        for(int i=ind+1; i<=min(n,ind+arr[ind]); i++) {
            ans = ans || solve(i,n,arr,dp);
        }
        return dp[ind] = ans;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums.size()-1,nums,dp);
    }
};