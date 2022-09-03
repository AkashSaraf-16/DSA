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
    bool isSym(TreeNode* lTree ,TreeNode* rTree){
        if(lTree== NULL && rTree != NULL)   return false;
        if(lTree!= NULL && rTree == NULL)   return false;
        if(lTree== NULL && rTree == NULL)   return true;        
        if(lTree->val != rTree->val )   return false;
        return (isSym(lTree->left,rTree->right) && isSym(lTree->right,rTree->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSym(root->left , root->right);
        
    }
};