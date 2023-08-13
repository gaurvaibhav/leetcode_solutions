#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
public:
	bool solve(vector<int> &arr, int ind, int n, vector<int> &dp)
	{
        op;
		if (ind == n)
			return true;
		if (dp[ind] != -1)
			return dp[ind];
		bool ans = false;
		if (ind + 1 < n && arr[ind] == arr[ind + 1])
			if (solve(arr, ind + 2, n, dp))
				ans = true;
		if (ind + 2 < n && arr[ind] == arr[ind + 1] && arr[ind] == arr[ind + 2])
			if (solve(arr, ind + 3, n, dp))
				ans = true;
		if (ind + 2 < n && arr[ind] + 1 == arr[ind + 1] && arr[ind + 1] + 1 == arr[ind + 2])
			if (solve(arr, ind + 3, n, dp))
				ans = true;
		return dp[ind] = ans;
	}
	bool validPartition(vector<int> &nums)
	{
        op;
		int n = nums.size();
		vector<int> dp(n + 1, -1);
		return solve(nums, 0, n, dp);
	}
};