#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        op;op;
        int n = nums.size();
        if((n == 1 && m>=1) || n == 2) return true;
        for(int i=0; i<n-1; ++i) {
            if(nums[i]+nums[i+1] >= m) return true;
        }
        return false;
    }
};