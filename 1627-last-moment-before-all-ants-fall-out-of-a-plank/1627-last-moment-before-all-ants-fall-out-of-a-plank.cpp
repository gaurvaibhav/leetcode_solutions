class Solution
{
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right)
    {
        int i, res, s1, s2;
        res = 0;
        s1 = left.size();
        s2 = right.size();
        for(i=0; i<s1; ++i)
        {
           res = max(res, (abs(left[i])));  
        }
        for(i=0; i<s2; ++i)
        {
           res = max(res, abs(n - right[i]));        
        }
        return res;        
    }
};