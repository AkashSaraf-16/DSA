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
        int count = 0 ;
public:
    void dfs(TreeNode* root, long long int targetSum){  // going DFS wise to explore every subtree that can exist
        if(!root)
            return;
        if(targetSum == root->val){             
            count++;
        }
        dfs(root->left,targetSum-root->val);
        dfs(root->right,targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){        // trying every node to get the sum while traversing DFS w/o missing in between nodes
            dfs(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return count;
        // T.C - O(N^2) S.C - O(N^2)
    }
};