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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int width = 0;
        queue<pair<TreeNode*,int>> q;  // to store the node and its index
        q.push({root,0});
        while(!q.empty()){
            int qSize = q.size();       // we are storing q.size() in var becoz it will change inside the loop and hence we cant make proper level wise calculations
            int minIndex = q.front().second;   // to avoid overflow of int and start every level from 1-N
            int firstIndex,lastIndex;
            for(int i = 0 ; i < qSize ; i++){
                long int currIndex = q.front().second-minIndex; // to avoid overflow of int
                TreeNode* frnt = q.front().first;
                q.pop(); 
                if(i==0) firstIndex = currIndex;        // storing extreme left
                if(i==qSize-1) lastIndex = currIndex;    // storing extreme right
                if(frnt->left) 
                    q.push({frnt->left,2*currIndex+1});
                if(frnt->right) 
                    q.push({frnt->right,2*currIndex+2});
            }
            width = max(width,lastIndex-firstIndex+1);
        }
        return width;
    }
};