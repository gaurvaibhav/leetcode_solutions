/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
private:
    int i, n;
    vector<int> ds;
    void inorder(TreeNode* root, vector<int>& ds)
    {
        if(root)
        {
            inorder(root->left, ds);
            ds.push_back(root->val);
            inorder(root->right, ds);
        }
    }
public:
    BSTIterator(TreeNode* root)
    {
        i = 0;
        inorder(root, ds);
        n = ds.size();
    }
    
    int next()
    {
        return ds[i++];
    }
    
    bool hasNext()
    {
        return (i<n);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */