#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int uniquePaths(int m, int n) {
        op;
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n ; j++){
                if(i==0 && j==0) continue;
                int l=0,u=0;
                if(j>0) l=dp[i][j-1];
                if(i>0) u=dp[i-1][j]; 
                dp[i][j] = l+u;
            }
        }
        return dp[m-1][n-1];
    }
};