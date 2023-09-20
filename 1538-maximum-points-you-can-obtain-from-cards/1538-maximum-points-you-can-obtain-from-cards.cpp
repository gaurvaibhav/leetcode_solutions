#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        FASTIO;
        int res, curr, i, j;
        i = res = curr = 0;
        j = nums.size()-1;
        while(i<k) {
            curr += nums[i];i++;
        }
        res = curr;i--;
        while(i>=0) {
            curr -= nums[i];
            curr += nums[j];
            i--;j--;
            res = max(res, curr);
        }
        return res;
    }
};