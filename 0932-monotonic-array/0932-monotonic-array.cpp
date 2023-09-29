class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int x = 0 ;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                x = 1 ;
                break ;
            }
        }
        for(int i=0; i<nums.size()-1; i++) {
            if(x == 0 && nums[i] > nums[i+1]) return false ;
            if(x == 1 && nums[i] < nums[i+1]) return false ;
        }
        return true ;
    }
};