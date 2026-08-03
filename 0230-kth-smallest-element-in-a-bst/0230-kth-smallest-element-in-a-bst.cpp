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
    int inorderRec(TreeNode* root, int &count , int k){
        if(!root) return -1;
        int left=inorderRec(root->left,count,k);
        if(left!=-1) return left;
        count++;
        if(count==k) return root->val;
        int right=inorderRec(root->right,count,k);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        return inorderRec(root,count,k);
    }
};