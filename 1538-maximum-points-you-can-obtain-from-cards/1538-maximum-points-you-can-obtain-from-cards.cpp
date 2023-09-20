class Solution {
private:
    int minSumSubarrayOfSizeK(vector<int>& nums, int k) {
        int i, j, res, curr;
        i = j = res = curr = 0;
        while(j<k) {
            curr += nums[j];
            j++;
        }
        res = curr;j--;
        while(j<nums.size()) {
            if(j-i+1 == k) {
                res = min(res, curr);
            } 
            j++;
            if(j<nums.size()) curr += nums[j];
            curr -= nums[i];
            i++;
        }
        return res;
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        for(int& it: cardPoints) total += it;
        int n = cardPoints.size();
        return total - minSumSubarrayOfSizeK(cardPoints, n-k);
    }
};