/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        if (root->val == key)
            return helper(root);
        TreeNode* curr = root;
        while (root) {
            if (key < root->val) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return curr;
    }

    TreeNode* helper(TreeNode* root) {
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* findRight(TreeNode* root) {
        if (root->right == NULL)
            return root;
        return findRight(root->right);
    }
};