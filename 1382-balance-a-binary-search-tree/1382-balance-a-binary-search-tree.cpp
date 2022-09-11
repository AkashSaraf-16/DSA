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
    TreeNode* buildBST(vector<int> inorder, int s ,int e){
        if(s>e) return NULL;
        int m = s+(e-s)/2;
        TreeNode *root = new TreeNode(inorder[m]);
        root->left = buildBST(inorder,s,m-1);
        root->right = buildBST(inorder,m+1,e);
        return root;
    }
    void traversalInorder(TreeNode* root, vector<int> &inorder){
        if(!root)
            return;
        traversalInorder(root->left,inorder);
        inorder.push_back(root->val);
        traversalInorder(root->right,inorder);
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        traversalInorder(root,inorder);        // for creating an array using inorder traversal
        return buildBST(inorder,0,inorder.size()-1);     // for creating a balanced BST
    }
};