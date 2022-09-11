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
    int findUnivaluePath(TreeNode* root, int &len){
        if(!root)
            return 0;
        int lenL = findUnivaluePath(root->left,len);
        int lenR = findUnivaluePath(root->right,len);
        
        int l = 0, r = 0;
        if(root->left && root->val == root->left->val)
            l = lenL+1;
        if(root->right && root->val == root->right->val)
            r = lenR+1;        
        
        len = max(len,l+r);     // longest univalue path
        return max(l,r);        // max of left and right path
    }
    int longestUnivaluePath(TreeNode* root) {
        int len = 0;
        findUnivaluePath(root,len);     // this will return the height of longest path having same val nodes 
        return len;
    }
};