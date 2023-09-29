class Solution
{
public:
    int numTeams(vector<int>& arr)
    {
        int res, i, j, n, t1, t2, t3, t4;
        res = 0;
        n = arr.size();
        for(i=0; i<n; ++i)
        {
            t1 = t2 = t3 = t4 = 0;
            for(j=0; j<n; ++j)
            {
                if(j<i)
                {
                    if(arr[j] < arr[i])
                    {
                        t1++;
                    }
                    else 
                    {
                        t2++;
                    }
                }
                if(j>i)
                {
                    if(arr[j] < arr[i])
                    {
                        t3++;
                    }
                    else 
                    {
                        t4++;
                    }
                }
            }
            res += (t1 * t4) + (t2 * t3);
        }
        return res;
    }
};