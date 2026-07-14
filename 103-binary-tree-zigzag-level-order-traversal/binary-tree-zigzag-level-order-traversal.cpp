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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(!root) return {};
        q.push(root);
        int zig = false;
        while(!q.empty()){
            int qSize = q.size();
            zig = !zig;
            vector<int> lev(qSize);

            for(int i = 0; i < qSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int idx = zig ? i : qSize - 1 - i;
                lev[idx] = temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(lev);
        }

        return ans;
    }
};