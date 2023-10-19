class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int n, m, i, j, k;
        n = s.length(); m = t.length();
        i = j = 0;
        for(k=0; k<n; ++k)
        {
            if(s[k] == '#') --i, i = max(0, i);
            else s[i] = s[k], ++i;
        }
        for(k=0; k<m; ++k)
        {
            if(t[k] == '#') --j, j = max(0, j);
            else t[j] = t[k], ++j;
        }
        if(i != j) return false;
        for(k=0; k<i; ++k)
        {
            if(s[k] != t[k]) return false;
        }
        return true;
    }
};