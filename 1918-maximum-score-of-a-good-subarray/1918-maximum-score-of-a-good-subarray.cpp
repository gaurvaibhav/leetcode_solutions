class Solution
{
public:
    int maximumScore(vector<int>& nums, int k)
    {
        int i, j, mn, mx, n;
        i = j = k;
        mn = nums[k];
        mx = mn;
        n = nums.size();
        while(i >= 1 || j < n-1)
        {
            if(i == 0 || (j < n-1 && nums[j+1] > nums[i-1])) ++j;
            else --i;
            mn = min(mn, min(nums[i], nums[j]));
            mx = max(mx, mn * (j-i+1));
        }
        return mx;
    }
};