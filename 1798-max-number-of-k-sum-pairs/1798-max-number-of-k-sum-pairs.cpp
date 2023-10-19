class Solution
{
public:
    int maxOperations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res, i, j, n;
        n = nums.size();
        i = res = 0, j = n-1;
        while(i < j)
        {
            if((nums[i] + nums[j]) == k)
            {
                ++i;--j;++res;
            }
            else if((nums[i] + nums[j]) > k) --j;
            else ++i;
        }
        return res;
    }
};