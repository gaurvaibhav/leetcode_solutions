#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    int findC(int ind,int target,vector<int> &arr, int n, vector<vector<int>>& dp){
        op;
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int res = 0;
        for(int i=0; i<n; ++i) {
            res += findC(i, target-arr[i], arr, n, dp);
        }
        return dp[ind][target] = res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        op;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return findC(0, target, nums, n, dp);
    }
};