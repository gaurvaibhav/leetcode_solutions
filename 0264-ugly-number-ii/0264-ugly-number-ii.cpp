class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int a, b, c, i, tm, thm ,fm;
        vector<int> dp(n);
        dp[0] = 1;
        a = b = c = 0;
        for(i=1; i<n; ++i)
        {
            tm = dp[a] * 2;
            thm = dp[b] * 3;
            fm = dp[c] * 5;
            dp[i] = min(tm, min(thm, fm));
            if(dp[i] == tm) a++;
            if(dp[i] == thm) b++;
            if(dp[i] == fm) c++;
        }
        return dp[n-1];
    }
};