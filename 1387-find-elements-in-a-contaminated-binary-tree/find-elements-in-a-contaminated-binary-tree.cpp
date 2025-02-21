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
class FindElements {
public:
    unordered_set<int>st;
    void dfs(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return;

        // st.insert(root->val);

        if(root->left!=NULL){
            root->left->val=2*root->val+1;
            st.insert(root->left->val);
            dfs(root->left);
        }
        if(root->right!=NULL){
            root->right->val=2*root->val+2;
            st.insert(root->right->val);
            dfs(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        st.insert(0);
        dfs(root);
    }
    
    bool find(int target) {
        if(st.count(target)!=0) return true;
        else return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */