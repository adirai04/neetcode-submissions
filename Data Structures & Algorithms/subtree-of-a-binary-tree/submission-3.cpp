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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }

        if (!root) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        bool a = isSubtree(root->left, subRoot);
        bool b = isSubtree(root->right, subRoot);

        return a || b;
    }

    bool isSameTree(TreeNode* first, TreeNode* second) {
        if (!first && !second) {
            return true;
        }

        if (!first || !second) {
            return false;
        }

        if (first->val != second->val) {
            return false;
        }

        bool a = isSameTree(first->left, second->left);
        bool b = isSameTree(first->right, second->right);

        return a && b;
    }
};
