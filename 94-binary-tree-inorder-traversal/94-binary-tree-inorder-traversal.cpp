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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
     /*   stack<TreeNode*> s;
        if(!root)
            return res;
        TreeNode* curr = root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;*/
    // MORRIS TRAVERSAL
    // TC:O(N) SC:O(1)
        TreeNode* curr;
        curr = root;
        while(curr){
            if(curr->left == NULL){ // if no left child store the node and move to right tree
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                // going on to rightmost node of left tree(last node of inorder traversal)
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right; 
                }
                // making the connection if it is not made already
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                // if for the first time than make the connection with the curr
                else{
                    prev->right = NULL;
                    // store the curr in res
                    res.push_back(curr->val);
                    curr = curr->right;
                }
                
            }
        }
        return res;
    }
};