#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        FASTIO;
        int n, p, s, e, mid, r;
        n = mountainArr.length();
        s = 1; e = n - 2;p = -1;
        while(s < e)
        {
            mid = s + (e - s) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        } 
        p = s;
        s = 0;
        e = p;  
        while(s <= e)
        {
            mid = s + (e - s) / 2;
            r = mountainArr.get(mid);
            if(r == target) return mid;
            if(r > target) e = mid - 1;
            else s = mid + 1;
        }
        s = p; e = n - 1;
        while(s <= e)
        {
            mid = s + (e - s) / 2;
            r = mountainArr.get(mid);
            if(r == target) return mid;
            if(r < target) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }
};