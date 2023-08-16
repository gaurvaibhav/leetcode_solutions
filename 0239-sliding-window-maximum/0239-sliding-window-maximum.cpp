#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
        op;
		int n = nums.size();
		vector<int> ans;
		deque<int> q;
		if (n == 1)
			return nums;
		int i = 0, j = 0;
		while (j < n)
		{
			if (j - i + 1 == k)
			{
				if (j < n && q.front() < nums[j])
				{
					while (!q.empty() && q.front() < nums[j])
						q.pop_front();
					q.push_back(nums[j]);
				}
				else if (j < n && q.front() >= nums[j])
				{
					while (q.back() < nums[j])
						q.pop_back();
					q.push_back(nums[j]);
				}
				ans.push_back(q.front());
				if (nums[i] == q.front())
				{
					q.pop_front();
				}
				i++;
				j++;
			}
			else
			{
				if (j == 0)
					q.push_back(nums[j]);
				else if (nums[j] > q.front())
				{
					while (!q.empty() && q.front() < nums[j])
						q.pop_front();
					q.push_back(nums[j]);
				}
				else if (nums[j] <= q.front())
				{
					while (q.back() < nums[j])
						q.pop_back();
					q.push_back(nums[j]);
				}
				j++;
			}
		}
		return ans;
	}
};