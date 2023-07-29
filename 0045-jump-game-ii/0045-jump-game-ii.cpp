#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    int solve(int ind, vector<int>& arr,vector<int>& dp){
        op;
        if(ind >= arr.size()-1) return 0;
        if(dp[ind] != 1e9) return dp[ind];
        for(int i=1; i<=arr[ind]; i++) {
            dp[ind] = min(dp[ind],1+solve(ind+i,arr,dp));
        }
        return dp[ind];
    }
    int jump(vector<int>& nums) {
        op;
        vector<int> dp(nums.size(),1e9);
        return solve(0,nums,dp);
    }
};