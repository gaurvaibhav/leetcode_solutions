class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        if(!root) return res;
        TreeNode* f;
        int n, ans, i;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            n = q.size();
            ans = INT_MIN;
            for(i=0; i<n; ++i)
            {
                f = q.front();
                q.pop();
                ans = max(ans, f->val);
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
            }
            res.push_back(ans);
        }
        return res;
    }
};