#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution
{
private:
    ll solve(ll n)
    {
        FASTIO;
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        if(n == 5) return 6;
        if(n == 6) return 9;
        return 3 * solve(n-3);
    }
public:
    ll integerBreak(ll n)
    {
        FASTIO;
        return solve(n);
    }   
};