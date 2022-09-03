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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        /*stack<TreeNode*> s;
        if(!root) return {};
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }*/
        
    // MORRIS TRAVERSAL
    // TC:O(N) SC:O(N)
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
                    // store the curr in res
                    res.push_back(curr->val);
                    curr = curr->left;
                }
                // if connection is already made just breeak it
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
                
            }
        }
        return res;

    }
};