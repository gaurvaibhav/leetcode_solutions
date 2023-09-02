class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1,mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if (target==nums[mid]) return mid;
            else if (nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
};