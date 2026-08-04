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
    void help(TreeNode* root, int k, int& count, int& ans){
        if(!root) return;

        help(root->left, k, count, ans);
        if(count==k) ans = root->val;
        count++;
        help(root->right, k, count, ans); 
    } 

    int kthSmallest(TreeNode* root, int k) {
        int count=1;
        int ans = -1;
        help(root, k, count, ans);
        return ans;
    }
};