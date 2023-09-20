class Solution {
private:
    int getLongestSubarray(vector<int>& a, int k) {
        int n = a.size(); 
        int left = 0, right = 0; 
        int sum = a[0];
        int maxLen = 0;
        while (right < n) {
            while (left <= right && sum > k) {
                sum -= a[left];
                left++;                                         
            }
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
            if (right < n) sum += a[right];
        }
        return maxLen;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        int res, aux, k;
        res = nums.size();
        if(nums[0]>x && nums[res-1]>x) return -1;
        aux = 0; 
        for(int& it: nums) aux+=it;
        if(aux == x) return res;
        if(aux < x) return -1;
        k = aux-x;
        aux = getLongestSubarray(nums, k);
        res -= aux;
        return res;
    }
};