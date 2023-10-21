class Solution
{
private:
    TreeNode* solve(vector<int>& preo, vector<int>& ino, int& root, int l, int r)
    {
        if(l > r) return NULL;
        int newRoot = l;
        while(ino[newRoot] != preo[root]) newRoot++;root++;
        TreeNode* res = new TreeNode(ino[newRoot]);
        res->left = solve(preo, ino, root, l, newRoot-1);
        res->right = solve(preo, ino, root, newRoot+1, r);
        return res;
    }
public:
    TreeNode* buildTree(vector<int>& preo, vector<int>& ino)
    {
        int root = 0;
        return solve(preo, ino, root, 0, ino.size()-1);
    }
};