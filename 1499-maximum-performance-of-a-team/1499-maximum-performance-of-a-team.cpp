#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution
{
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k)
    {
        FASTIO;
        vector<pair<int, int>> arr;
        priority_queue<int, vector<int>, greater<int>> pq;
        ll res, curr;
        int e, s;
        res = INT_MIN;
        curr = 0;
        for(int i=0; i<n; ++i)
        {
            arr.push_back({eff[i], sp[i]});
        }
        sort(arr.rbegin(), arr.rend());
        for(int i=0; i<n; ++i)
        {
            e = arr[i].first;
            s = arr[i].second;
            curr += s;
            pq.push(s);
            if(pq.size() > k)
            {
                curr -= pq.top();
                pq.pop();
            }
            res = max(res, curr * e);
        }
        return res % MOD;
    }
};