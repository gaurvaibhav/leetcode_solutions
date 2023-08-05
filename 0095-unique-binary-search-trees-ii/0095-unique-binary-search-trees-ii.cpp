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
#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution {
public:
    vector<TreeNode*> solve(int start, int end)
    {
        op;op;
        vector<TreeNode*> arr;
        if (start > end) {
            arr.push_back(NULL);
            return arr;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = solve(start, i - 1);
            vector<TreeNode*> rightSubtrees = solve(i + 1, end);
            for (auto it1 : leftSubtrees) {
                for (auto it2 : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = it1;
                    root->right = it2;
                    arr.push_back(root);
                }
            }
        }

        return arr;
    }
    vector<TreeNode*> generateTrees(int n) {
        op;op;
        vector<TreeNode*> res;
        if (n != 0) res = solve(1, n);
        return res;
    }
};