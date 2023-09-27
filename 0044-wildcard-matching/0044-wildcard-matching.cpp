class Solution 
{
private:
    int solve(string& p, string& s,int n,int m, vector<vector<int>>& dp) 
    {
        if(n < 0 && m < 0) return true;
        if(n < 0 && m >= 0) return false;
        if(m < 0 && n >= 0) 
        {
            for(int i=0; i<=n; i++) 
            {
                if(p[i] != '*') return false;
            }
            return true;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if(p[n] == s[m] || p[n] == '?')
        {
            return dp[n][m] = solve(p, s, n-1, m-1, dp);
        }
        if(p[n] == '*') 
        {
            return dp[n][m] = (solve(p, s, n-1, m, dp) | solve(p, s, n, m-1, dp));
        }
        return dp[n][m] = false;
    }
public:
    bool isMatch(string s, string p) 
    {
        int n = p.length();
        int m = s.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(p, s, n-1, m-1, dp);
    }
};