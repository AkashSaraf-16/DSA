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
    bool helper(TreeNode* root , long long minV = -10000000000 , long long maxV = 10000000000){
        if(root == NULL)
            return true;
        bool left,right;
        if(root->val > minV && root->val < maxV){
         left = helper(root->left , minV , root->val);  // here we are passing root->val as maximum becoz left tree should be less than this val
         right = helper(root->right , root->val , maxV);// here we are passing root->val as minimum becoz right tree should be greater than this val
        }
        else
            return false;
        
        if(left && right)
            return true;
        else 
            return false;   
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};