#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        op;
        int n = nums.size();
        int mid, l = 0, h = n-1;
        while(l<=h) {
            mid = l + (h-l) /2 ;
            if(nums[mid] == target) return true;
            if(nums[l] == nums[mid] &&  nums[mid] == nums[h]) {l++,h--;continue;}
            if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && nums[mid] >= target) {
                    h = mid-1;
                }
                else l = mid + 1;
            }
            else {
                if(nums[mid] <= target && target <= nums[h]) l = mid+1;
                else h = mid-1;
            }
        }
        return false;
    }    
};