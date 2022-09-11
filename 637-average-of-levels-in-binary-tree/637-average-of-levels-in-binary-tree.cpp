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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root)
            return ans;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double sum = 0;
        double avg ;
        int n = 0;
        while(!q.empty()){
            TreeNode* frnt = q.front();
            q.pop();
            if(frnt == NULL){       // end of level
                avg = sum/n;
                ans.push_back(avg);
                sum = 0;
                n = 0;
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                sum+= frnt->val;
                n++;
                if(frnt->left)  q.push(frnt->left);
                if(frnt->right) q.push(frnt->right);
            }
        }
        return ans;
    }
};