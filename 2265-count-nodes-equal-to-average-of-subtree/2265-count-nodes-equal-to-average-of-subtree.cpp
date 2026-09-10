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
    int ans=0;
    pair<int,int> dfs(TreeNode* node){
        if(node==NULL)return{0,0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int sum = node->val + left.first + right.first;
        int count =  1 + left.second + right.second;
        if(sum/count == node->val){
            ans++;
        }
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};