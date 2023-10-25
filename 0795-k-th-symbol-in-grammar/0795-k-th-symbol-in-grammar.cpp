#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
private:
    int solve(int n, int k)
    {
        FASTIO;
        if(n == 1) return 0;
        if(k & 1) return solve(n-1, (k+1)/2);
        else 
        {
            if(solve(n-1, k/2)) return 0;
            else return 1;
        }
    }
public:
    int kthGrammar(int n, int k)
    {
        FASTIO;
        return solve(n, k);
    }
};