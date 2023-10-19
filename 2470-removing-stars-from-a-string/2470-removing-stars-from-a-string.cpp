class Solution
{
public:
    string removeStars(string s)
    {
        string res;
        int i, n = s.length();
        for(i=0; i<n; ++i)
        {
            if(s[i] == '*' && !res.empty()) res.pop_back();
            else if(s[i] != '*') res.push_back(s[i]);
        }
        return res;
    }
};