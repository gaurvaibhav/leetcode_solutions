#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int numTrees(int n) {
        op;op;
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; ++i) {
            for(int j=1; j<=i; ++j) {
                dp[i] += dp[j-1] * dp[i-j]; 
            }
        }
        return dp[n];
    }
};