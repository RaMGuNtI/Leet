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
    int searchNode(vector<int> &inorder, int node, int left, int right){
        for(int i=left; i<=right; i++){
            if(inorder[i]==node) return i;
        }

        return -1;
    }

    TreeNode* createNode(vector<int>& preorder, vector<int>& inorder, int &rotIdx, int left, int right){
        if(left>right) return nullptr;

        TreeNode* root = new TreeNode(preorder[rotIdx]);
        int searchRoot = searchNode(inorder, preorder[rotIdx], left, right);
        rotIdx++;
        root->left = createNode(preorder, inorder, rotIdx, left, searchRoot-1);
        root->right = createNode(preorder, inorder, rotIdx, searchRoot+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rotIdx = 0;
        return createNode(preorder, inorder, rotIdx, 0, inorder.size()-1);       
    }
};