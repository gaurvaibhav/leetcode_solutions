#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    int findC(int ind,int target,vector<int> &arr, int n, vector<int>& dp){
        op;
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target]!=-1) return dp[target];
        int res = 0;
        for(int i=0; i<n; ++i) {
            res += findC(i, target-arr[i], arr, n, dp);
        }
        return dp[target] = res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        op;
        int n = nums.size();
        vector<int> dp(target+1, -1);
        return findC(0, target, nums, n, dp);
    }
};