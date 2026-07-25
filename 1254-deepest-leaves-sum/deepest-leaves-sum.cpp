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
    int maxDepth = INT_MIN;

    void goDown(TreeNode* root, int currDepth){
        if(!root) return;

        if(currDepth>maxDepth){
            ans = 0;
            maxDepth = currDepth;
        }
        if(maxDepth==currDepth) ans+=root->val;

        goDown(root->left, currDepth+1);
        goDown(root->right, currDepth+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        goDown(root, 0);
        return ans;
    }
};