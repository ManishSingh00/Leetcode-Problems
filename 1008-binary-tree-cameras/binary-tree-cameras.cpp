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
    map<pair<TreeNode*,pair<bool,bool>>,int> dp;
    int f(TreeNode* u,bool cam,bool par_cam){
        if(u ==NULL){
            if(cam) return 1e5;
            else return 0;
        }
        if(u->left ==NULL && u->right ==NULL){
            if(cam){
                return 1;
            }
            else{
                if(par_cam) return 0;
                else return 1e5;
            }
        }
        if(dp.find({u,{cam,par_cam}})!=dp.end()) return dp[{u,{cam,par_cam}}];
        if(cam){
            return dp[{u,{cam,par_cam}}] = 1 + min(f(u->left,1,1),f(u->left,0,1)) + min(f(u->right,1,1),f(u->right,0,1));
        }
        else{
            if(par_cam){
                return dp[{u,{cam,par_cam}}] = min(f(u->left,0,0),f(u->left,1,0)) + min(f(u->right,1,0),f(u->right,0,0));
            }
            else{
                int case1 = f(u->left,1,0) + min(f(u->right,1,0),f(u->right,0,0));
                int case2 = f(u->right,1,0) + min(f(u->left,1,0),f(u->left,0,0));
               return dp[{u,{cam,par_cam}}] = min(case1,case2);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        dp.clear();

        return min(f(root,0,0),f(root,1,0));
    }
};