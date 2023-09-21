class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res, a, i, j, n;
        n = nums.size();
        sort(nums.begin(), nums.end());
        res = nums[0] + nums[1] + nums[3];
        for(a=0; a<nums.size()-2; a++) {
            i = a+1, j = n-1;
            while(i < j) {
                int sum = nums[a] + nums[i] + nums[j];
                if(sum == target) return sum;
                if(abs(sum-target) < abs(target-res)) res = sum;
                if(sum > target) j--;
                else i++;
            }
        }
        return res;
    }
};