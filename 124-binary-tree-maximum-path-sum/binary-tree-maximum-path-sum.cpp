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
    int maxDownPath(TreeNode*root, int &ans){
        if(!root) return 0;

        int l = maxDownPath(root->left, ans);
        if(l<0) l = 0;
        int r = maxDownPath(root->right, ans);
        if(r<0) r = 0;

        ans = max(ans, root->val+l+r);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;

        maxDownPath(root, ans);
        return ans;
    }
};