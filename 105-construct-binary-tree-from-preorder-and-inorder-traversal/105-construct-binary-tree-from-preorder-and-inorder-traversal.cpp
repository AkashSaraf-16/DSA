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
    TreeNode* auxBuildTree(vector<int> preorder,vector<int> inorder,int inS,int inE,int poS,int poE){
        if(inS>inE)
            return NULL;

        int rootData = preorder[poS];
        int rootIndex= -1;
        
        for(int i = inS ; i<=inE ; i++){
            if(inorder[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        }
        
        int LInS = inS;
        int LInE = rootIndex - 1;
        int LPoS = poS + 1;
        int LPoE = LPoS + LInE - LInS;
        
        int RInS = rootIndex + 1;
        int RInE = inE;
        int RPoS = LPoE + 1;
        int RPoE = poE;
        
        
        TreeNode* root = new TreeNode(rootData);
        root->left = auxBuildTree(preorder,inorder,LInS,LInE,LPoS,LPoE);
        root->right = auxBuildTree(preorder,inorder,RInS,RInE,RPoS,RPoE);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     int n = preorder.size();
     return auxBuildTree(preorder,inorder,0,n-1,0,n-1);
    }
};