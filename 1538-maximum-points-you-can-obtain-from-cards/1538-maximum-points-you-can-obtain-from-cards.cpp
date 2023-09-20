class Solution {
private:
    int minSumSubarrayOfSizeK(vector<int>& arr, int k)
    {
        int n =arr.size();
        if (n < k)
        {
            return -1;
        }
        int res = 0;
        for (int i=0; i<k; i++)
            res += arr[i];
        int curr_sum = res;
        for (int i=k; i<n; i++)
        {
            curr_sum += arr[i] - arr[i-k];
            res = min(res, curr_sum);
        }
        return res;
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        for(int& it: cardPoints) total += it;
        int n = cardPoints.size();
        return total -  minSumSubarrayOfSizeK(cardPoints, n-k);
    }
};