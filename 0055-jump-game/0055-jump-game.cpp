class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,false);
        dp[n-1] = true;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] == false) dp[i] = false;
            else if(nums[i] >= n-1-i) dp[i]=true;
            else {
                for(int j=1; j<=nums[i]; j++) {
                    dp[i] = dp[i] || dp[i+j];
                }
            }
        }
        return dp[0];
    }
};