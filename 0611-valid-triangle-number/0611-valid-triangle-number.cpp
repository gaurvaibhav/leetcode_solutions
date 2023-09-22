class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res, i, j, k, n;
        res = 0, n = nums.size();
        for(k=n-1; k>1; --k) {
            i = 0, j = k-1;
            while(i<j) {
                if(nums[i] + nums[j] > nums[k]) {
                    res += j-i;
                    --j;
                }
                else ++i;
            }
        }
        return res;
    }
};