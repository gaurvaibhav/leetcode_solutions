class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i, j;
        i = nums[0];
        j = nums[nums[0]];
        while(i != j) {
            i = nums[i];
            j = nums[nums[j]];
        }
        j = 0;
        while(i != j) {
            i = nums[i];
            j = nums[j];
        }
        return i;
    }
};