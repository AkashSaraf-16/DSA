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
private:
    // T.C:O(n) S.C:O(1)
    TreeNode *first , *middle , *last , *prev;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        
        if(prev && prev->val > root->val){
            // if there is element which is smaller than previous element
            if(!first){
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev  = new TreeNode(INT_MIN);
        inorder(root);
        if(first && !last)  swap(first->val,middle->val);   // incase adjacent nodes are swapped
        if(last)    swap(first->val,last->val); // incase non-adjacent nodes are swapped
    }
};