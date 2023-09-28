class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i, j, n;
        i = j = 0;
        n = nums.size();
        while(i<n && nums[i]%2 == 0) i++,j++;
        while(i<=j && j<n)
        {
            if(nums[j]%2)
            {
                j++;
            }
            else 
            {
                swap(nums[i], nums[j]);
                i++, j++;
            }
        } 
        return nums;
    }
};