#define vi vector<int>
class Solution
{
public:
    int maxCoins(vi& a)
    {
        int i, j, n, res;
        n = a.size();
        res = i = 0; j = n-2;
        sort(a.begin(), a.end());
        while(i < j)
        {
            res += a[j];
            i++;
            j-=2;
        }
        return res;
    }
};