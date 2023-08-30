#define ll long
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    ll minimumReplacement(vector<int>& nums) {
        FASTIO;
        ll ans = 0, p;
        int n=nums.size(), e=nums.back();
        for(int i=n-2; i>=0; --i) {
            if(nums[i]<=e) e=nums[i]; 
            else {
                p = ((nums[i]-1)/e)+1;
                e = nums[i]/p;
                ans += (p-1);
            }
        }
        return ans;
    }
};