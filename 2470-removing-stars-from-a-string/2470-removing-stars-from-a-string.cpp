#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    string removeStars(string s)
    {
        FASTIO;
        string res;
        int i, j, n = s.length();
        i = j = 0;
        for(j=0; j<n; ++j)
        {
            if(s[j] == '*')
            {
                --i;
                i = max(0, i);
            }
            else 
            {
                s[i] = s[j];
                i++;
            }
        }
        for(j=0; j<i; ++j)
            res.push_back(s[j]);
        return res;
    }
};