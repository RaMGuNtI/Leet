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
    void push_left(TreeNode* root, stack<TreeNode*>& s){
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> ans;
        push_left(root1, s1);
        push_left(root2, s2);
        
        while(!s1.empty() || !s2.empty()){
            if(s1.empty() || (!s2.empty() && s1.top()->val>s2.top()->val)){
                TreeNode* temp = s2.top();
                s2.pop();
                ans.push_back(temp->val);
                if(temp->right) push_left(temp->right, s2);
            }else{
                TreeNode* temp = s1.top();
                s1.pop();
                ans.push_back(temp->val);
                if(temp->right) push_left(temp->right, s1);
            }
        }
        
        return ans;
    }
};