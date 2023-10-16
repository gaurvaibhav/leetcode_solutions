#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
public:
    int sumNumbers(TreeNode* root)
    {
        FASTIO;
        int res;
        res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size())
        {
            auto [n, curr] = q.front();
            q.pop();
            curr = curr * 10 + n->val;
            if(n->left) q.push({n->left, curr});
            if(n->right) q.push({n->right, curr});
            if(!n->left && !n->right) res += curr;
        }
        return res;
    }
};