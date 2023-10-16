#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        FASTIO;
        vector<int> prev(rowIndex+1,0);
        prev[0] = 1 ;
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=i; j>=1; j--)
            {
                prev[j] += prev[j-1] ;
            }
        }
        return prev ;
    }
};