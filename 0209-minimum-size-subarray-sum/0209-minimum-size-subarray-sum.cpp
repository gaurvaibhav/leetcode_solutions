#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        FASTIO;
        int i, j, n = nums.size(), res;
        res = n + 1;
        i = j = 0;
        while(j<n) {
            target -= nums[j];
            while(target <= 0) {
                res = min(res, j-i+1);
                target += nums[i];
                i++;
            }
            ++j;
        }n++;
        return res%n;
    }
};