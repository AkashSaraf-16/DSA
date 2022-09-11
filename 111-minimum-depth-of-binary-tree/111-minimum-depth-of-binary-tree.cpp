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
    int height(TreeNode* root){
        if(!root)
            return 0;
        int h;
        if(!root->left)         // incase only right node exist we have to find the height
            h = height(root->right)+1;
        else if(!root->right)   // incase only left node exist we have to find the height
            h = height(root->left)+1;
        else{                   // when we have leaf node it will be the min height among the 2 
            h = min(height(root->left),height(root->right))+1;
        }
        return h;
    }
    int minDepth(TreeNode* root) {
        return height(root);
    }
};