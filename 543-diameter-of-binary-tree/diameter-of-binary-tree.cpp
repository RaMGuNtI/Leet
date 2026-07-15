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
    int height(TreeNode* root, int &ans){
        if(!root) return 0;
        int lefHeight = height(root->left, ans);
        int rigHeight = height(root->right, ans);

        ans = max(lefHeight+rigHeight, ans);

        return 1+max(lefHeight, rigHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        height(root, ans);

        return ans;
    }
};