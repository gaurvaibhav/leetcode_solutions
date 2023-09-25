#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
class Solution
{
private:
    vector<int> findNextSmaller(vector<int>& arr) 
    {
        FASTIO;
        int n, i;
        stack<int> stc;
        n = arr.size();
        vector<int> res(n, -1);
        for(i=0; i<n; ++i)
        {
            while(!stc.empty() && arr[i] < arr[stc.top()])
            {
                res[stc.top()] = i;
                stc.pop();
            }
            stc.push(i);
        }
        return res;
    }
    vector<int> findPrevSmaller(vector<int>& arr) 
    {
        FASTIO;
        int n, i;
        stack<int> stc;
        n = arr.size();
        vector<int> res(n, -1);
        for(i=n-1; i>=0; --i)
        {
            while(!stc.empty() && arr[i] < arr[stc.top()])
            {
                res[stc.top()] = i;
                stc.pop();
            }
            stc.push(i);
        }
        return res;
    }
    vector<ll> prefixSolve(vector<int>& arr, int n)
    {
        FASTIO;
        int aux;
        vector<int> ps = findPrevSmaller(arr);
        vector<ll> res;
        for(int i=0; i<n; ++i) 
        {
            aux = ps[i];
            if(aux == -1) res.push_back(1LL * arr[i] * (i + 1));
            else 
            res.push_back(res[aux] + (1LL * arr[i] * (i - aux)));
        }
        return res;
    }
    vector<ll> suffixSolve(vector<int>& arr, int n)
    {
        FASTIO;
        int aux;
        vector<int> ns = findNextSmaller(arr);
        vector<ll> res(n, 0);
        for(int i=n-1; i>=0; --i) 
        {
            aux = ns[i];
            if(aux == -1) res[i] = (1LL * arr[i] * (n - i));
            else 
            res[i] = (res[aux] + (1LL * arr[i] * (aux - i)));
        }
        return res;
    }
public:
    long long maximumSumOfHeights(vector<int>& maxHeights)
    {
        FASTIO;
        int n = maxHeights.size();
        vector<ll> p = prefixSolve(maxHeights, n);
        vector<ll> s = suffixSolve(maxHeights, n);
        ll ans;
        ans = 0;
        for(int i=0; i<n; ++i)
        {
            ans = max(ans, p[i] + s[i] - maxHeights[i]);
        }
        return ans;
    }
};