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
        if(!root)
            return {};
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* curr=root;
        st.push(curr);
        while(!st.empty()){
            curr=st.top();
            res.push_back(curr->val);
            st.pop();
            if(curr->right)     st.push(curr->right);
            if(curr->left)     st.push(curr->left);
        }
        return res;
    }
};