class Solution
{
private:
    pair<int, int> solve(TreeNode* root, int& res)
    {
        if(!root) return {0, 0};
        auto [ls, lc] = solve(root->left, res);
        auto [rs, rc] = solve(root->right, res);
        int cs,cc;
        cs = root->val + ls + rs;
        cc = 1 + lc + rc;
        if(cs / cc == root->val) ++res;
        return {cs, cc};
    }
public:
    int averageOfSubtree(TreeNode* root)
    {
        int res;
        res = 0;
        solve(root, res);
        return res;
    }
};