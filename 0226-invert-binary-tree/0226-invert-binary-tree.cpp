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
    // TC:O(N) SC:O(logN)
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* t=stk.top();
            stk.pop();
            if(t->left) stk.push(t->left);
            if(t->right) stk.push(t->right);
            swap(t->left,t->right);
        }
        return root;
    }
};