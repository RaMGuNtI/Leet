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
    vector<int> co1;
    vector<int> co2;
    void getLeafElements(TreeNode* head, vector<int> &ve){
        if(!head) return;
        if(!head->left && !head->right){
            ve.push_back(head->val);
            return;
        }
        
        getLeafElements(head->left, ve);
        getLeafElements(head->right, ve);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeafElements(root1, co1);
        getLeafElements(root2, co2);
        for(int i: co1){
            cout<<i<<" ";
        }
        cout<<endl;

        for(int i: co2){
            cout<<i<<" ";
        }
        cout<<endl;
        return co1==co2;
    }
};