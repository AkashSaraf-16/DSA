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
    int sum;
    int sum_dfs(TreeNode* root,int number){
        int digit;
        if(!root)
            return 0;
        if(!root->left && !root->right){
            digit = root->val;
            number = number*10+digit;
            sum+= number;
            return number;
        }
        digit = root->val;
        number = number*10+digit;
        int l = sum_dfs(root->left,number);
        int r = sum_dfs(root->right,number);

        return l+r;
        
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        sum_dfs(root,0);
        return sum;
    }
};