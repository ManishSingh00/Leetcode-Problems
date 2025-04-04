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
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        return max(dfs(root->left),dfs(root->right))+1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==right) return root;
        else if(left>right){
            return subtreeWithAllDeepest(root->left);
        }
        else return subtreeWithAllDeepest(root->right);
    }
};