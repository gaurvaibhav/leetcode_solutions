class Solution {
private:
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;
        else
            return (n & 1) + countSetBits(n >> 1);
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            if(countSetBits(i) == k) res+=nums[i];
        }
        return res;
    }
};