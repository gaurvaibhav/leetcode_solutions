class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int preSum, cnt;
        map<int, int> mp;
        mp[0] = 1;
        preSum = cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];
            int rem = preSum - goal;
            cnt += mp[rem];
            mp[preSum] += 1;
        }
        return cnt;
    }
};