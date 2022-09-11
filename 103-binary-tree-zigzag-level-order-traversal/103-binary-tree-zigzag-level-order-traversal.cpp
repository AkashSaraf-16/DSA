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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(!root)
            return ans;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int i = 0;          // indicator of level to reverse
        while(!q.empty()){
            TreeNode* frnt = q.front();
            q.pop();
            if(frnt == NULL){       // whole level is traversed
                if(i%2)
                    reverse(temp.begin() , temp.end());
                ++i;
                ans.push_back(temp);
                temp.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                temp.push_back(frnt->val);
                if(frnt->left)  q.push(frnt->left);
                if(frnt->right) q.push(frnt->right);
            }
        }
        return ans;
    }
};
// TC:O(N) SC:O(N)