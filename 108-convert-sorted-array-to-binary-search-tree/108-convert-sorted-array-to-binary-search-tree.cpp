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
    TreeNode* createBST(vector<int> nums , int s , int e){
        if(s>e)
            return NULL;
        int m = (s+e)/2;
        int rootData = nums[m];
        TreeNode* root = new TreeNode(rootData);
        root->left = createBST(nums , s , m-1);
        root->right = createBST(nums , m+1 , e);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       int n = nums.size();
       return createBST(nums , 0 , n-1);
    }
};