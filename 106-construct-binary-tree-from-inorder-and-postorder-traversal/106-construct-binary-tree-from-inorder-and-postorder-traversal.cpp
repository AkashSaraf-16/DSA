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
TreeNode* auxBuildTree(vector<int> postorder,vector<int> inorder,int inS,int inE,int poS,int poE){
        if(inS>inE)
            return NULL;

        int rootData = postorder[poE];
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
        int LPoS = poS;
        int LPoE = LPoS + LInE - LInS;
        
        int RInS = rootIndex + 1;
        int RInE = inE;
        int RPoS = LPoE + 1;
        int RPoE = poE-1;
        
        
        TreeNode* root = new TreeNode(rootData);
        root->left = auxBuildTree(postorder,inorder,LInS,LInE,LPoS,LPoE);
        root->right = auxBuildTree(postorder,inorder,RInS,RInE,RPoS,RPoE);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     int n = postorder.size();
     return auxBuildTree(postorder,inorder,0,n-1,0,n-1);        
    }
};
