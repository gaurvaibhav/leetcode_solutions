#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        op;
        int n = cost.size();
        int prev = cost[0];
        int curr = cost[1];
        for(int i=2;i<n;i++)
        {
            int temp = cost[i] + min(curr, prev);
            prev = curr ;
            curr = temp ;
        }
        return min(prev,curr);
    }
};