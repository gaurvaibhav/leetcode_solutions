#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution
{
private:
    unordered_set<ll> s;
    unordered_map<ll, ll> dp;
    ll solve(int a, vector<int>& arr)
    {
        FASTIO;
        if(s.find(a) == s.end()) return 0;
        if(dp.find(a) != dp.end()) return dp[a];
        ll ans = 1, i, n = arr.size();
        for(i=0; i<n; ++i)
        {
            if(a % arr[i] == 0 && s.find(a/arr[i]) != s.end())
            {
                ans += (solve(arr[i], arr) % MOD * solve(a/arr[i], arr) % MOD) % MOD;
            }
        }
        return dp[a] = ans;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        FASTIO;
        s = unordered_set<ll>();
        dp = unordered_map<ll, ll>();
        ll n, res, i;
        n = arr.size(); 
        res = 0;
        for(auto it: arr)
        {
            s.insert(it);
        }
        for(i=0; i<n; ++i)
        {
            res += solve(arr[i], arr);
        }
        return res % MOD;
    }
};