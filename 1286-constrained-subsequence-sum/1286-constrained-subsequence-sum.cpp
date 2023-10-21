class Solution
{
public:
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        int i, n = nums.size();
        vector<int> res(n);
        multiset<int> s = {0};
        for(i=0; i<n; ++i)
        {
            res[i] = nums[i] + (*s.rbegin());
            s.insert(res[i]);
            if(i >= k)
            s.erase(s.find(res[i - k]));
        }
        return (*(max_element(res.begin(), res.end())));
    }
};