class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        char c;
        string res = "";
        vector<int> vis(26, 0), mp(26, 0);
        int n;
        n = s.length();
        for(char& c: s)
        {
            mp[c-'a']++;
        } 
        for(int i=0; i<n; ++i) 
        {
            c = s[i];
            mp[c-'a']--;
            if(!vis[c-'a'])
            {
                while(res.length() > 0 && mp[res.back()-'a'] > 0 && res.back() > c)
                {
                    vis[res.back()-'a'] = 0;
                    res.pop_back();
                }
                vis[c-'a'] = 1;
                res += c;
            }
        }
        return res;
    }
};