class Solution
{
private:
    void inOrderTraversal(vector<int>& arr, TreeNode* root)
    {
        if(root)
        {
            inOrderTraversal(arr, root->left);
            arr.push_back(root->val);
            inOrderTraversal(arr, root->right);
        }
    }
    TreeNode* balenceBST(vector<int>& arr, int l, int r)
    {
        if(l <= r)
        {
            int mid = l + (r-l) / 2;
            TreeNode* root = new TreeNode(arr[mid]);
            root->left = balenceBST(arr, l, mid-1);
            root->right = balenceBST(arr, mid+1, r);
            return root;
        }
        return 0;
    }
public:
    TreeNode* balanceBST(TreeNode* root)
    {
        TreeNode* res;
        vector<int> arr;
        inOrderTraversal(arr, root);
        res = balenceBST(arr, 0, arr.size()-1);
        return res;
    }
};