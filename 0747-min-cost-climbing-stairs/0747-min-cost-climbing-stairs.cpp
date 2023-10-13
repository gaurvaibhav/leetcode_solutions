#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        op;
        int n, prev, curr, i, temp;
        n = cost.size();
        prev = cost[0];
        curr = cost[1];
        for(i=2; i<n; i++)
        {
            temp = cost[i] + min(curr, prev);
            prev = curr ;
            curr = temp ;
        }
        return min(prev,curr);
    }
};