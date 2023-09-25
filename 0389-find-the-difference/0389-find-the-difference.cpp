class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int res, n, i;
        res = 0; n = s.length();
        for(i=0; i<n; i++) 
        {
            res ^= (int)s[i];
            res ^= (int)t[i];
        }
        res ^= (int)t[n];
        return (char)res;
    }
};