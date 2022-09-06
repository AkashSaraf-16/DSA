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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
        TreeNode* frnt = q.front();
        q.pop();
        if(frnt == NULL){
            ans.push_back(temp);       // temp stores nodes at a same level
            temp.clear();            // to clear the current values once its get in ans
            if(!q.empty())
                q.push(NULL);
        }
        else{
            temp.push_back(frnt->val);
            if(frnt->left)
                q.push(frnt->left);
            if(frnt->right)
                q.push(frnt->right);
        }
        }
        return ans;
    }
};