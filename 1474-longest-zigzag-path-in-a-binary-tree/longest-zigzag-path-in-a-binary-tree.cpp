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
    int ans = 0;
    void f(TreeNode* root,int flag,int len){
        if(root == NULL) return;
        ans = max(ans, len);
        if(flag == 0){
            f(root->left,1,1);
            f(root->right,2,1);
        }
        else if(flag==1){
           f(root->right,2,len+1);
           f(root->left,1,1);
        }
        else if(flag==2){
            f(root->left,1,len+1);
            f(root->right,2,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        f(root,0,0);
        return ans;      
    }
};