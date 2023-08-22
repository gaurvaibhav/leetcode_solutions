class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int prev2 = 1,prev = 2;
        for(int i=2;i<n;i++){
            int curr_i = prev2 + prev;
            prev2 = prev;
            prev = curr_i;  
        }
        return prev;
    }
};