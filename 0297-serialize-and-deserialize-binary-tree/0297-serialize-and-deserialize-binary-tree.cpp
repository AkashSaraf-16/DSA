/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string level wise # -> NULL
    string serialize(TreeNode* root) {
        string encoded="";
        if(root==NULL)
            return encoded;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* frnt=q.front();
            q.pop();
            if(frnt!=NULL){
                encoded.append(to_string(frnt->val)+',');
                q.push(frnt->left);
                q.push(frnt->right);
            }
            else
                encoded.append("#,");
        }
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* frnt=q.front();
            q.pop();
            // Now getting the left child
            getline(s,str,',');
            if(str=="#"){
                frnt->left=NULL;
            }
            else{
                TreeNode* l=new TreeNode(stoi(str));
                frnt->left=l;
                q.push(l);
            }
            // Now getting the right child
            getline(s,str,',');
            if(str=="#"){
                frnt->right=NULL;
            }
            else{
                TreeNode* r=new TreeNode(stoi(str));
                frnt->right=r;
                q.push(r);
            }
        }
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));