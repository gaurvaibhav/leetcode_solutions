class Solution
{
private:
    void inOrd(TreeNode* root, vector<int>& arr) 
    {
        if(!root) return;
        inOrd(root->left, arr);
        arr.push_back(root->val);
        inOrd(root->right, arr);
    }
public:
    vector<int> findMode(TreeNode* root)
    {
        int mx = 0;
        vector<int> arr, res;
        inOrd(root, arr);
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); ++i)
        {
            mp[arr[i]]++;
            mx = max(mx, mp[arr[i]]);
        }
        for(int i=0; i<arr.size(); ++i)
        {
            if(mx == mp[arr[i]]) res.push_back(arr[i]), mp[arr[i]] = -1;
        }
        return res;
    }
};