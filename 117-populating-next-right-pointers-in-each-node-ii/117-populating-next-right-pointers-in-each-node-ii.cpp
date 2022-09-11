/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> q;         // using queue for level ordre traversal
        q.push(root);           // pushing root
        q.push(NULL);           // pusing a marker so that we can mark end of level
        while(!q.empty()){
            Node* frnt = q.front(); // pickinf front node 
            q.pop();
            if(frnt){               // making connections
                frnt->next = q.front();
            }
            else{                   // if we reach marker 
                if(!q.empty())      // we will check is it the end of whole B tree
                    q.push(NULL);
            }
            if(frnt && frnt->left)  // pushing left and right nodes if exist
                q.push(frnt->left);
            if(frnt && frnt->right)
                q.push(frnt->right);
        }
        return root;
    }
};