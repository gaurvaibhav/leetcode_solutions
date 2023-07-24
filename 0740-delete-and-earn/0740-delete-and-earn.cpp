#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
public:
    int solve(vector<int> &arr, int ind, int n, vector<int>& dp)
    {
        op;
        if (ind >= n)
            return 0;
        if (dp[ind] != -1) return dp[ind];
        int t = arr[ind];
        int j;
        for (j = ind + 1; j < n && arr[j] == arr[ind]; j++)
        {
            t += arr[j];
        }
        while (j < n && arr[j] == arr[ind] + 1)
            j++;
        return dp[ind] = max(t + solve(arr, j, n, dp), solve(arr, ind + 1, n, dp));
    }
    int deleteAndEarn(vector<int> &nums)
    {
        op;
        int n = nums.size();
        vector<int> dp(n,-1);
        sort(nums.begin(), nums.end());
        return solve(nums, 0, n, dp);
    }
};