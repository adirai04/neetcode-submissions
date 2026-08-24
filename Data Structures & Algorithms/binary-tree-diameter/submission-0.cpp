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
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHt  = height(root->left);
        int rightHt = height(root->right);

        ans = max(ans, leftHt + rightHt);

        return 1 + max(leftHt, rightHt);
    }
};