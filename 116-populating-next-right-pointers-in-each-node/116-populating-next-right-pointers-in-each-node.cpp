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
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* frnt = q.front();
            q.pop();
            if(frnt){
                frnt->next = q.front();
            }
            else{
                if(!q.empty())
                    q.push(NULL);
            }
            if(frnt && frnt->left)
                q.push(frnt->left);
            if(frnt && frnt->right)
                q.push(frnt->right);
        }
        return root;
    }
};