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
    // ITERATIVE 1 : USING 2 STACKS  
    // TC:O(N) SC: 2 stacks used
    // here we are simply stroing the track of the traversal in the second stack while using first stack to traverse the tree.
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root)   return postorder;
    /*    stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* t = st1.top();
            st1.pop();
            st2.push(t);
            if(t->left)
                st1.push(t->left);
            if(t->right)
                st1.push(t->right);
        }
        while(!st2.empty()){
            int v = st2.top()->val;
            st2.pop();
            postorder.push_back(v);
        }
        return postorder;*/
    // ITERATIVE 2 : USING SINGLE STACK
    // TC : O(2N) SC : O(N)
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            if(curr){           // Traversing and storing the left nodes
                st.push(curr);
                curr = curr->left;
            }
            else{
               TreeNode* temp = st.top()->right;    // going right once we have nthng on left
                if(!temp){              // if we are on leaf node 
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){   // if temp is right child of the node present at top on stack
                        temp = st.top();                // we will simply add it to our ans vector since there is no node to process 
                        postorder.push_back(temp->val); // in between
                        st.pop();
                    }
                }
                else{
                    curr = temp;    // if we have a node who have right tree so we will process this node by traversing left-right-root                    
                }
            }
        }
        return postorder;
    }
};