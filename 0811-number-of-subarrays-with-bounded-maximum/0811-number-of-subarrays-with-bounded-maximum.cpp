class Solution
{
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right)
    {
        int res, i, j, k, n;
        res = 0;
        i = j = -1;
        n = nums.size();
        for(k=0; k<n; ++k)
        {
            if(nums[k] > right)
                i = k;
            if(nums[k] >= left)
                j = k;
            res += j-i;
        }
        return res;
    }
};