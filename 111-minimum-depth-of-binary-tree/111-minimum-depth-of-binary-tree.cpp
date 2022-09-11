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
    int height(TreeNode* root){
        if(!root)
            return 0;
        int h;
        if(!root->left)         // incase only right node exist we have to find the height
            h = height(root->right)+1;
        else if(!root->right)   // incase only left node exist we have to find the height
            h = height(root->left)+1;
        else{                   // when we have other than leaf node it will be the min height among the 2 
            h = min(height(root->left),height(root->right))+1;
        }
        return h;
    }
    int minDepth(TreeNode* root) {
        // Recursive : 
        //return height(root);
        // Iterative : we will go BFS , since in BFS we will encounter the leaf node anywhere if it present in the level we dont need to find the min. as soon as we encounter the leaf node we will get the ans;
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int i =0 ;
        while(!q.empty()){
            i++;                        // inc. the i since we have a node
            int k = q.size();
            for(int j = 0 ; j<k ; j++){       // getting all the elements in a level for particular node
                TreeNode* rt = q.front();
                if(rt->left)    q.push(rt->left);
                if(rt->right)   q.push(rt->right);
                q.pop();
                if(!rt->left && !rt->right)         // incase of leaf node we will return the i 
                    return i; 
            }
        }
        return -1;
    }
};