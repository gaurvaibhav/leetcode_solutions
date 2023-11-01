class Solution
{
private:
    int c = 0, m = 0, n = INT_MIN;
    vector<int> res;
    void inOrd(TreeNode* root) 
    {
        if(!root) return;
        inOrd(root->left);
        if(n == root->val) c++;
        else
        {
            n = root->val;
            c = 1;
        }
        if(c > m)
        {
            m = c;
            res = {root->val};
        }
        else if(c == m)
        {
            res.push_back(root->val);
        }
        inOrd(root->right);
    }
public:
    vector<int> findMode(TreeNode* root)
    {
        inOrd(root);
        return res;
    }
};