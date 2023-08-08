#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int BS(vector<int>& nums, int s, int e, int k) {
        op;
        while(s<=e) {
            int mid = s + ((e-s)/2);
            if(nums[mid] == k) return mid;
            else if(nums[mid] > k) e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
    int findPivot(vector<int>& nums) {
        op;
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
    int search(vector<int>& nums, int target) {
        op;
        int pv = findPivot(nums);
        int a,b;
        a = BS(nums,0,pv-1,target);
        b = BS(nums,pv,nums.size()-1,target);
        if(a != -1) return a;
        return b;
    }
};