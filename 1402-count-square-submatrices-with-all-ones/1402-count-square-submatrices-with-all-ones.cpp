class Solution
{
public:
    int countSquares(vector<vector<int>>& arr)
    {
        int n, m, i, j, res;
        n = arr.size();
        m = arr[0].size();
        res = 0;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                if(i && j && arr[i][j]) 
                arr[i][j] = 1 + min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1]));
                res += arr[i][j];
            }
        }
        return res;
    }
};