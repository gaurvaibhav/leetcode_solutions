#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    void recPerm (int ind, vector<int> &nums, vector<vector<int>> &ans) {
        op;op;
        if (ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size() ; ++i)
        {
            swap(nums[ind],nums[i]);
            recPerm(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute (vector<int> &nums) {
        op;op;
        vector<vector<int>> ans;
        recPerm(0,nums,ans);
        return ans;
    }
};