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
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans = 0;
        while(q.size()>0){
            auto curr = q.front();
            q.pop();
            if(curr->val%2==0){
                if(curr->left!=NULL && curr->left->left!=NULL) ans+= curr->left->left->val;
                if(curr->left!=NULL &&curr->left->right!=NULL) ans += curr->left->right->val;

                if(curr->right!=NULL && curr->right->left!=NULL) ans += curr->right->left->val;
                if(curr->right!=NULL && curr->right->right!=NULL) ans += curr->right->right->val;
            }
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right); 
        }

        return ans;
    }
};