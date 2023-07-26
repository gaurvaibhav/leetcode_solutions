#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        op;
        while(start < end) {
            swap(nums[start],nums[end]);
            start++;end--;
        }
    }       
    void rotate(vector<int>& nums, int k) {
        op;
        int n = nums.size();
        if(n < k) k = k % n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};