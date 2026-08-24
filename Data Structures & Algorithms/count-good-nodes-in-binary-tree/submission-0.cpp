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
    int goodNodes(TreeNode* root) {
        int a = INT_MIN;
        return solve(root, a);
    }

    int solve(TreeNode* &root, int maxValSoFar) {
        if (!root) {
            return 0;
        }

        int left = 0, right = 0;

        int rootVal = root->val;
        if (rootVal >= maxValSoFar) {
            left  = solve(root->left, rootVal);
            right = solve(root->right, rootVal);

            return 1 + left + right;
        } else {
            left  = solve(root->left, maxValSoFar);
            right = solve(root->right, maxValSoFar);

            return left + right;
        }
    }
};