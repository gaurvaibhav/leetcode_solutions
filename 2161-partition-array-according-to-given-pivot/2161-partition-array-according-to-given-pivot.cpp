#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
public:
	vector<int> pivotArray(vector<int> &nums, int pivot)
	{
        op;
		int n = nums.size();
		vector<int> res(n);
		int l = 0, eq = 0, r;
		for (int ele : nums)
		{
			if (ele < pivot)
				++l;
			else if (ele == pivot)
				++eq;
		}
		r = l + eq;
		eq = l;
		l = 0;
		for (int ele : nums)
		{
			if (ele < pivot)
				res[l++] = ele;
			else if (ele == pivot)
				res[eq++] = ele;
			else if (ele > pivot)
				res[r++] = ele;
		}
		return res;
	}
};