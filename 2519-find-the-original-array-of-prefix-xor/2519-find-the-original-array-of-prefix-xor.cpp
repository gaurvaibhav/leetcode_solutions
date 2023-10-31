#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
public:
    vector<int> findArray(vector<int>& pref)
    {
        FASTIO;
        int exor = 0, i, n;
        n = pref.size();
        for(i=1; i<pref.size(); i++)
        {
            exor ^= pref[i-1];
            pref[i] = exor^pref[i];
        }
        return pref;
    }
};