class Solution
{
public:
    int getWinner(vector<int>& arr, int k)
    {
        int res, w, i, n;
        res = arr[0];
        n = arr.size();
        w = 0;
        for(i=1; i<n; ++i)
        {
            if(arr[i] > res)
            {
                res = arr[i];
                w = 0;
            }
            w++;
            if(w == k) break;
        }
        return res;
    }
};