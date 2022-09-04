class Solution {
public:
    // got to learn about pointers in detail 
    void swap(TreeNode** left, TreeNode** right)    // here left and right are pointer to pointer becoz they are storing the address of a pointer(root->left/right)
    {
        TreeNode* temp = *left;     // here temp is pointer becoz it is storing the content of  left(double pointer) and not its address
        *left = *right;
        *right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        
        swap(&root->left, &root->right);    // here we are passing the address of left and right pointers
        
        return root;
    }
};