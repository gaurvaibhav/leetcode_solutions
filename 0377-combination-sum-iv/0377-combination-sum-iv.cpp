#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        op;
        int n = nums.size();
        ll MOD = 1e18+7;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; ++i) {
            for(int j=0; j<n; ++j) {
                if(i >= nums[j]) {
                    dp[i] = (1ll*dp[i] + dp[i-nums[j]]) % MOD;
                }
            }
        }
        return dp[target];
    }
};