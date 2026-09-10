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
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<TreeNode*> add;
        add.push_back(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* tp = q.front();
            q.pop();
            if(tp->right){
                q.push(tp->right);
                add.push_back(tp->right);
            }
            if(tp->left){
                q.push(tp->left);
                add.push_back(tp->left);
            }
        }
        int ans = 0;

        for(int i=0; i<add.size(); i++){
            queue<TreeNode*> nq;
            nq.push(add[i]);
            int sumo =0;
            int numCount = 0;
            while(!nq.empty()){
                TreeNode* tp = nq.front();
                numCount++;
                sumo+=tp->val;
                nq.pop();
                if(tp->right){
                    nq.push(tp->right);
                }
                if(tp->left){
                    nq.push(tp->left);
                }
            }
            cout<<"sumo: "<<sumo<<", numCount: "<<numCount<<endl;
            if(floor(sumo/numCount)==add[i]->val){
                ans++;
            }
        }

        return ans;
    }
};