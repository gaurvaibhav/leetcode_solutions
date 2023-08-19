#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    int solve(vector<int>& nums, int i, int last, vector<vector<int>>& dp){
        op;
        if(i < 0 ) return 0;
        if(last < 1) return 1000;
        if(dp[i][last] != -1 ) return dp[i][last];
        int res = INT_MAX;
        if(last == nums[i]) res = solve(nums, i-1, last, dp);
        else{
            if(nums[i] < last) res = min(res, solve(nums, i-1, nums[i], dp));
            res = min(res, 1 + solve(nums, i-1, last, dp));
            res = min(res, 1 + solve(nums, i-1, last-1, dp));
        }
        return dp[i][last] = res;
    }
    int minimumOperations(vector<int>& nums) {
        op;
        vector<vector<int>> dp(nums.size()+1, vector<int>(4, -1));
        return solve(nums, nums.size()-1, 3, dp);
    }
};