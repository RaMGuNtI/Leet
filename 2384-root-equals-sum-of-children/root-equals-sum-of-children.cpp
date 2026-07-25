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
    bool checkNodeVal(TreeNode* root){
        if(!root) return false;
        if(!root->left && !root->right) return true;
        if(root->left && root->right){
            return root->val==root->left->val+root->right->val && checkNodeVal(root->left) && checkNodeVal(root->right);
        }else if(root->left && !root->right){
            return root->val==root->left->val && checkNodeVal(root->left);
        }else{
            return root->val==root->right->val && checkNodeVal(root->right);
        }

    }

    bool checkTree(TreeNode* root) {
        return checkNodeVal(root);
    }
};