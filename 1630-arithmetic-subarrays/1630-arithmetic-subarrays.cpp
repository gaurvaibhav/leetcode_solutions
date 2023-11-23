#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
class Solution
{
public:
    vb checkArithmeticSubarrays(vi& nums, vi& l, vi& r)
    {
        FASTIO;
        int i, n, j;
        n = l.size();
        bool f;
        vi aux;
        vb res(n);
        for(i=0; i<n; ++i)
        {
            aux.clear();
            for(j=l[i]; j<=r[i]; ++j)
            {
                aux.pb(nums[j]);
            }
            if(aux.size() <= 1)
            {
                res[i] = true;
            }
            else
            {
                sort(aux.begin(), aux.end());
                f = true;
                for(j=1; j<aux.size(); ++j)
                {
                    if(aux[j] - aux[j-1] != aux[1] - aux[0])
                    {
                        f = false;
                        break;
                    }
                }
                res[i] = f;
            }
        }
        return res;
    }
};