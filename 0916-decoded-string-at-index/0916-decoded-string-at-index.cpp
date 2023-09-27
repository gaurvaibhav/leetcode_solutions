#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        FASTIO;
        ll ds;
        int i, n;
        char c;
        n = s.length();
        ds = 0;
        for(char& c: s)
        {
            if(isdigit(c))
            {
                ds *= (c-'0');
            }
            else 
            {
                ds++;
            }
        }
        for(i=n-1; i>=0; --i)
        {
            c = s[i];
            k = k % ds;
            if(k == 0 && !isdigit(c))
            {
                return string("") + c;
            }
            if(isdigit(c)) 
            {
                ds /= (c-'0');
            }
            else
            {
                ds--;
            }
        }
        return NULL;
    }
};