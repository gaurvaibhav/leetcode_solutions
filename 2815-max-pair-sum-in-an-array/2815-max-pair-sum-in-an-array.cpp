#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    int GD(int n) {
        op;
        int res = 0;
        while(n!=0) {
            if(res < n%10) {
                res = n%10;
            }
            n/=10;
        }
        return res;
    }
    int maxSum(vector<int>& nums) {
        op;
        int res=-1;
        for(int i=0; i<nums.size()-1; ++i) {
            int aux1 = GD(nums[i]);
            for(int j=i+1; j<nums.size(); ++j) {
                int aux2 = GD(nums[j]);
                if(aux1 == aux2) {
                    if(res<nums[i]+nums[j]){
                        res = nums[i]+nums[j];
                    }
                }
            }
        }
        return res;
    }
};