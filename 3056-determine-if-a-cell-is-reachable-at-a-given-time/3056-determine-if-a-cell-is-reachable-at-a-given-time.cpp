class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        if(sx == fx && sy == fy)
        {
            return !(t == 1);
        }
        int a = abs(sx-fx);
        if(abs(sy-fy)>a) a = abs(sy-fy);
        return (a <= t); 
    }
};