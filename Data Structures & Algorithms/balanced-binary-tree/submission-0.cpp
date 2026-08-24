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
    int ans = true;
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        if (abs(leftHt - rightHt) > 1) {
            ans = false;
        }

        return 1 + max(leftHt, rightHt);
    }
};
