#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        FASTIO;
        int n = nums.size(), p=-1;
        if(n==1 || nums[0]>nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int l=0, r=n-1, mid;
        while(l<=r) {
            mid = l+(r-l)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                p = mid;
                break;
            }
            else if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {
                l = mid+1;
            }
            else  {
                r = mid;
            }
        }
        return p;
    }
};