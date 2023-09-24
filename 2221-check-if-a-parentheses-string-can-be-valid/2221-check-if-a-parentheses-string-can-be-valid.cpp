class Solution 
{
public:
    bool canBeValid(string s, string locked) 
    {
        int o, c, n, i;
        n = s.length();
        o = c = 0;
        if(n & 1) return false;
        for(i=0; i<n; i++)
        {
            if(locked[i] == '0' || s[i] == '(') 
            ++o;
            else ++c;
            if(c > o) return false;
        }
        o = c = 0;
        for(i=n-1; i>=0; i--)
        {
            if(locked[i] == '0' || s[i] == ')') 
            ++o;
            else ++c;
            if(c > o) return false;
        }
        return true;
    }
};