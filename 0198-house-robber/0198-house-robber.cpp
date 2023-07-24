#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) ;
class Solution {
public:
    int rob(vector<int>& nums) {
        op;
        int n=nums.size();
        vector<int> dp(n,-1);
        int prev = 0;
        int curr = nums[0];
        for(int i=1;i<n;i++) {
            int t = nums[i];
            if(i>1) t+=prev;
            int temp = max(t,curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};