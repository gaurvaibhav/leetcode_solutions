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
class Solution {
public:
    void func(TreeNode* root, vector<int>& res) {
        if(root) {
            func(root->left, res) ;
            res.push_back(root->val) ;
            func(root->right, res) ;
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans ;
        func(root, ans) ;
        int res = 0 ;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] >= low && ans[i] <= high) res += ans[i] ;
        }
        return res ;
    }
};