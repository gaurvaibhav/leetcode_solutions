#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    string removeStars(string s)
    {
        FASTIO;
        int i = 0, j = 0, n = s.length();
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
        return s.substr(0, i);
    }
};