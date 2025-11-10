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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        stack<TreeNode*>st;

        while(curr != NULL || st.size()>0){

            while(curr != NULL){ // travel left subtree till null
                st.push(curr);
                curr = curr->left;
            }

            // here curr = NULL
            curr = st.top();
            ans.push_back(curr->val);
            st.pop();

            curr  = curr->right;

        }

        return ans;
    }
};