#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    bool solve(vector<int>& nums, int target, int l, int r) {
        op;
        while (l <= r) {
            if (nums[l++] == target) {
                return true;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        op;
        int l = 0, r = nums.size() - 1;
        while (l <= r && nums[l] != nums[r]) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return true;
            }
            if (nums[m] > target) {
                if (nums[l] > nums[m] || nums[l] <= target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[l] <= nums[m] || nums[l] > target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return solve(nums, target, l, r);
    }    
};