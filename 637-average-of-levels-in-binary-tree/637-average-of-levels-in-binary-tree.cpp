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
        vector<double> sum;
        vector<int> count;
        DFS(root,0,sum,count);
        for(int i = 0 ; i < sum.size() ; i++){
            sum[i] = sum[i]/count[i];
        }
        return sum;
    }
    void DFS(TreeNode* root, int level , vector<double> &sum , vector<int>& count){
        if(!root)
            return;
        if(level<sum.size()){
            sum[level] += 1.0*root->val;
            count[level]++;
        }else{
            sum.push_back(1.0*root->val);
            count.push_back(1);
        }
        DFS(root->left,level+1,sum,count);
        DFS(root->right,level+1,sum,count);
    }
};