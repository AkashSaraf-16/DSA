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
        /*stack<TreeNode*> st;
        vector<int> res;
        TreeNode* curr=root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
        return res;
        */
        // MORRIS TRAVERSAL:
        vector<int> res;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                // if nothing to process on left subtree
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                // We will try to make/check connection of rightmost node of this subtree with curr
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    // If we havent made any connection so far
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    // If connection is already there
                    prev->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return res;
    }
};