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
    bool helper(TreeNode* root, int targetSum){
        // BASE COND.
        if(!root->left && !root->right && targetSum == root->val)
            return true;
        
        bool leftS = false ,rightS = false;
        // HYPOTHESIS
        if(root->left)
            leftS =  helper(root->left , targetSum - root->val);    //INDUCTION
        if(root->right)
            rightS = helper(root->right , targetSum - root->val);   //INDUCTION
        
        return leftS || rightS;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return helper(root,targetSum);
    }
};