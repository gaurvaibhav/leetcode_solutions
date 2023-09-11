class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mp = 0, i, j, res, n = nums.size();
        i = j = res = 0;
        while(j < n) {
            while((mp & nums[j]) != 0) {
                mp ^= nums[i];
                i++;
            }
            mp = mp | nums[j];
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};