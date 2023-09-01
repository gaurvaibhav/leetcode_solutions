class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cmax = 0;
        for(int& it: nums) {
            if(it == 0) {
                res = max(res,cmax);
                cmax = 0;
            }
            else cmax++;
        }
        res = max(res,cmax);
        return res;
    }
};