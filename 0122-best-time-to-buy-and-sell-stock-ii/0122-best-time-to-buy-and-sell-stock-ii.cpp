#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        op;
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        dp[n][0] = dp[n][1] = 0 ;
        for(int i=n-1;i>=0; --i) {
            for(int j=0; j<=1; ++j) {
                int profit = 0 ;
                if(j) 
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else 
                    profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
            dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};