class Solution {
private:
    int findPivot(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        if(nums[s]<=nums[e]) return 0;
        while(s<=e) {
            int mid = s + ((e-s)/2);
            if(mid>=1 && nums[mid-1]>nums[mid]) return mid;
            else if(mid<=nums.size()-2 && nums[mid]>nums[mid+1]) return mid+1;
            else if(nums[s]>=nums[mid])
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
public:
    int findMin(vector<int>& nums) {
        int ind = findPivot(nums);
        return nums[ind];
    }
};