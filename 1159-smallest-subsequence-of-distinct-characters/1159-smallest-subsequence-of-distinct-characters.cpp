class Solution
{
public:
    string smallestSubsequence(string s)
    {
        string res = "";
        int vis[26] = {0}, mp[26] = {0};
        int n;
        n = s.length();
        for(char& c: s)
        {
            mp[c-'a']++;
        } 
        for(int i=0; i<n; ++i) 
        {
            mp[s[i]-'a']--;
            if(!vis[s[i]-'a'])
            {
                while(res.length() > 0 && mp[res.back()-'a'] > 0 && res.back() > s[i])
                {
                    vis[res.back()-'a'] = 0;
                    res.pop_back();
                }
                vis[s[i]-'a'] = 1;
                res += s[i];
            }
        }
        return res;
    }
};