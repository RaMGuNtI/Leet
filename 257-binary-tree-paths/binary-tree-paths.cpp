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
    void goToLeaf(TreeNode* root, vector<string> &ans, string cur) {
        if (!root) return;
        if(cur!=""){
            cur+="->"+to_string(root->val);
        }else{
            cur = to_string(root->val);
        }
    
        if (!root->left && !root->right) {
            ans.push_back(cur);
            return;
        }
    
        goToLeaf(root->left, ans, cur);
        goToLeaf(root->right, ans, cur);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        goToLeaf(root, ans, {});

        return ans;
    }
};