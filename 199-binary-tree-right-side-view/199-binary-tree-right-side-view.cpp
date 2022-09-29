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
    // we are doing reverse preorder traversal
    // TC:O(N)  SC:O(h)
    vector<int> res;
    void helper(TreeNode* root,int level){
        if(!root)
            return;
        if(level==res.size())
            res.push_back(root->val);
        
        helper(root->right,level+1);
        helper(root->left,level+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root,0);
        return res;
    }
};