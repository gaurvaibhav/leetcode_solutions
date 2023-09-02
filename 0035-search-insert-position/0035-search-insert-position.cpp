class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
        int numsSize = nums.size();
        if(nums[numsSize-1]<target){ 
            return numsSize;
        }
        int s = 0, e = numsSize - 1, ans = 0, mid;
        mid = s + ((e - s) / 2);
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
                s = mid + 1;
            else
            {
                ans = mid;
                e = mid - 1;
            }
            mid = s + ((e - s) / 2);
        }
        return ans;
    }
};