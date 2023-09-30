class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i, n, t;
        n = nums.size();
        t = INT_MIN;
        vector<int> arr;
        for(i=n-1; i>=0; --i)
        {
            if(nums[i] < t) return true;
            while(!arr.empty() && arr.back() < nums[i])
            {
                t = arr.back();
                arr.pop_back();
            }
            arr.push_back(nums[i]);
        }
        return false;
    }
};