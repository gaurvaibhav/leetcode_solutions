class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string a, b;
        int n, m, i;
        n = s.length(); m = t.length();
        for(i=0; i<n; ++i)
        {
            if(s[i] == '#' && !a.empty()) a.pop_back();
            else if(s[i] != '#') a.push_back(s[i]);
        }
        for(i=0; i<m; ++i)
        {
            if(t[i] == '#' && !b.empty()) b.pop_back();
            else if(t[i] != '#') b.push_back(t[i]);
        }
        return (a == b);
    }
};