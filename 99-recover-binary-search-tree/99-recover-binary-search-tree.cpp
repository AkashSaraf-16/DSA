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
    // T.C: O(nlogN) S.C: O(n)
    int ind = 0;
    void buildBST(vector<int> v , TreeNode* root){
        if(!root)
            return;
        buildBST(v,root->left);
        if(v[ind] != root->val)
            root->val = v[ind];
        ind++;
        buildBST(v,root->right);
    }
    void traversal(TreeNode* root , vector<int> &v){
        if(!root)
            return ;
        traversal(root->left,v);
        v.push_back(root->val);
        traversal(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        traversal(root,inorder);
        sort(inorder.begin() , inorder.end());
        buildBST(inorder,root);
    }
};