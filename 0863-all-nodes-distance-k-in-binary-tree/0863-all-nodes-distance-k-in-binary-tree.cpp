/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: 
    // Step1: We cant traverse from child to parent hence first map all the parents of node 
    // Step2: Do the BFS traversal and push all the nodes (incl parents) i.e., same leveled nodes
    // TC:O(N)  SC:O(N)
    void parentOfNodes(unordered_map<TreeNode*,TreeNode*>&mp,TreeNode*root){
        queue<TreeNode*> q;
           q.push(root);
           while(!q.empty()){
               TreeNode* curr = q.front();
               q.pop();
               if(curr->left){
                   mp[curr->left] = curr;
                   q.push(curr->left);
               }
               if(curr->right){
                   mp[curr->right] = curr;
                   q.push(curr->right);
               }
           }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;      // Mapping of node->parent
        parentOfNodes(mp,root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        int dist=0;
        vector<int> res;
        while(!q.empty()){
            int size=q.size();
            if(dist++==k)
                break;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && vis.find(curr->left)==vis.end()){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right && vis.find(curr->right)==vis.end()){
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(mp[curr] && vis.find(mp[curr])==vis.end()){
                    q.push(mp[curr]);
                    vis.insert(mp[curr]);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};