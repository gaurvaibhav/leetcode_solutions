#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define ll long long
#define MOD 1000000007
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        FASTIO;
        int i, n, t;
        n = nums.size();
        t = INT_MIN;
        vector<int> arr;
        for(i=n-1; i>=0; --i)
        {
            if(nums[i] < t) return true;
            while(!arr.empty() && arr.back() < nums[i])
            {
                t = arr.back();
                arr.pop_back();
            }
            arr.push_back(nums[i]);
        }
        return false;
    }
};