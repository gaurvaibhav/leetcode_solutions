class Solution
{
public:
    int poorPigs(int b, int md, int mt)
    {
        if(b == 1) return 0;
        b--;
        int res, lb;
        lb = mt / md + 1;
        res = 0;
        while(b > 0) 
        {
            b = b / lb;
            res++;
        }
        return res;
    }
};