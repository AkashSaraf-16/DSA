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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0 ;
        height(root,diameter);
        return diameter;
    }
    int height(TreeNode* root , int &diameter){
        // BASE CASE
        if(!root)
            return 0;
        // INDUCTION
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);
        
        // CALCULATION
        diameter = max(diameter,lh+rh);
        //HYPOTHESIS
        return  1 + max(lh,rh);         // returning height
    }
};