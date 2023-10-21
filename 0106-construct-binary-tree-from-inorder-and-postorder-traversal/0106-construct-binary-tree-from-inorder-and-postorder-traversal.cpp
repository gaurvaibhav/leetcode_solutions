class Solution
{
private:
    TreeNode* solve(vector<int>& posto, vector<int>& ino, int& proot, int l, int r)
    {
        if(l > r) return NULL;
        int newRoot;
        TreeNode* res = new TreeNode(posto[proot--]);
        newRoot = find(ino.begin(), ino.end(), res->val) - ino.begin();
        res->right = solve(posto, ino, proot, newRoot+1, r);
        res->left = solve(posto, ino, proot, l, newRoot-1);
        return res;
    }
public:
    TreeNode* buildTree(vector<int>& ino, vector<int>& posto)
    {
        int n = ino.size(), proot;
        proot = n-1;
        return solve(posto, ino, proot, 0, n-1);
    }
};